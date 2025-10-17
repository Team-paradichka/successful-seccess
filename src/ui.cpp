#include <iostream>
#include <string>
#include <vector>
#include "db.h" 
#include "ui.h"
#include "report.h"
#include <sstream>
using namespace std;


// Реалізація функцій інтерфейсу програми буде тут
// Наприклад, реалізація функції ShowMenu()
// void ShowMenu() {
//     std::cout << "Hello!" << std::endl;
// };
// зауважте що тип який повертає функція, аргументи які вона приймає, і її імʼя мають відповідати оголошенню в ui.h


void studentMenu() {
    int choise;
    do {
        std::cout << "\nChoose an option as a Student:\n";
        std::cout << "1 - Show all my grades\n";
        std::cout << "2 - Add a new score\n"; 
        std::cout << "3 - Show my average\n";
        std::cout << "0 - exit\n";
        std::cin >> choise;
        if (choise == 1) {
            printMyGrades();
        }
        else if (choise == 2) {
            if (db.getAllStudents().empty()) {
                std::cout << "No students in the database. Please add a student first.\n";
                continue;
            }
            auto student = db.getAllStudents()[0];
            AddScore(student.name);
        }
        else if (choise == 3) {
            auto student = db.getAllStudents()[0];
            double average = calculateAverageScore(student.subjects);
            std::cout << "Your average score is: " << average << "\n";
        }
        else if (choise == 0) {
            return;
        }
        else { 
            std::cout << "Choose a valid option.\n";
        }
    } while (choise != 0); //Цикл працює поки користувач не вийде в меню входу
    
}

void showTeacherMenu() {
    int choice = 0;

    while (true) {
        cout << "\n===== Teacher Main Menu =====" << endl;
        cout << "1. Display a student's grades" << endl;
        cout << "2. Show the list of all registered students" << endl;
        cout << "3. Add a new student" << endl;
        cout << "4. Find the best and worst student (by average grade)" << endl;
        cout << "5. Show a student's average grade" << endl;
        cout << "6. Show the group's average grade" << endl;
        cout << "7. Show the list of students receiving a scholarship (avg > 70)" << endl;
        cout << "8. Count the number of excellent students (avg > 88)" << endl;
        cout << "9. Show the list of students subject to expulsion (avg < 50)" << endl;
        cout << "10. Add student grade" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            printStudentScores();          
            break;
        case 2:
            printAllStudentsList();
            break;
        case 3:
            addStudentMenu();               
            break;
        case 4:
            printBestAndWorstStudents();
            break;
        case 5:
            printStudentAverage();
            break; 
        case 6:
            printGroupAverage();
            break;
        case 7:
            get_scholarship_student();
            break;
        case 8:
            printHonorStudents();
            break;
        case 9:
            printExpulsionList();
            break;
        case 10:
            addScoreMenu();
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice. Try again\n";
            break;
        }
    }
}


void AddScore(const std::string &studentName) {
    
    Student* student = db.findStudentByName(studentName); // Шукаємо студента в базі даних за іменем
    if (student == nullptr) { 
        cout << "Student not found!\n"; 
        return; 
    }
    
    
    cout << "\nSelect subject:\n"; 
    for (size_t i = 0; i < SUBJECT_NAMES.size(); ++i) { 
        cout << i + 1 << " - " << SUBJECT_NAMES[i] << "\n"; 
    }
    
    int choice; 
    cout << "Your choice: "; 
    cin >> choice; 
    cin.ignore(); // Очищуємо буфер від символу нового рядка після числа
    
    if (choice < 1 || choice > static_cast<int>(SUBJECT_NAMES.size())) { 
        cout << "Invalid choice!\n"; 
        return; 
    }
    
    string subjectName = SUBJECT_NAMES[choice - 1]; 
    
    // Вводимо оцінки
    cout << "Enter score: "; 
    int score; 
    cin >> score;
    if (score < 0 || score > 100) {
        cout << "Invalid score! Score must be between 0 and 100.\n";
        return;
    }
    student->addScore(subjectName, score);

    cout << "Added score to " << subjectName << "\n"; 
}
void addScoreMenu() {
    cout << "--- Add Score to Student ---\n";
    string name;
    cout << "Enter student name: ";
    cin >> name;
    
    Student* s = db.findStudentByName(name);
    if (!s) {
        cout << "Error: student not found!\n";
        return;
    }

    if (s->subjects.empty()) {
        s->subjects.push_back({"Mathematics"});
        s->subjects.push_back({"Physics"});
        s->subjects.push_back({"Chemistry"});
    }

    cout << "Available subjects:\n";
    for (size_t i = 0; i < s->subjects.size(); i++) {
        cout << i + 1 << ". " << s->subjects[i].name << endl;
    }

    int subChoice;
    cout << "Choose subject number: ";
    cin >> subChoice;
    cin.ignore();

    if (subChoice < 1 || subChoice > (int)s->subjects.size()) {
        cout << "Invalid choice!\n";
        return;
    }

    int score;
    cout << "Enter score: ";
    cin >> score;
    cin.ignore();

    if (score < 0 || score > 100) {
        cout << "Invalid score! Score must be between 0 and 100.\n";
        return;
    }

    s->subjects[subChoice - 1].scores.push_back(score);
    cout << "Score added successfully!\n";
}

void addStudentMenu() {
    cout << "--- Add New Student ---\n";
    string name;
    cout << "Enter student name: ";
    cin >> name;

    Student s;
    s.name = name;
    db.addNewStudent(name);

    cout << "Student '" << name << "' added successfully!\n";
}

void mainMenu()
{
    cout << "Welcome to ProStudentHelper!\nTo continue please choose one of the following options:" << endl;
    cout << "1 - Continue as a student\n2 - Continue as a teacher\n0 - Quit the program" << endl;
    int roleChoice;
    cin >> roleChoice;
    switch(roleChoice)
    {
        case 1:
            addStudentMenu();
            studentMenu();
            break;
        case 2:
            showTeacherMenu();
            break;
        case 0:
            return;
        default:
            cout << "Please, choose an apropriate option." << endl;
            mainMenu();
    }

}