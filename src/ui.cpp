#include <iostream>
#include <string>
#include <vector>
#include "db.h" 
#include "ui.h"
#include <sstream>
using namespace std;

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
        cout << "0. Return to the main menu" << endl;
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
        case 0:
            mainMenu();
            return;
        default:
            cout << "Invalid choice. Try again\n";
            break;
        }
    }



void AddScore() { // Функція для додавання оцінок, приймає базу даних за посиланням
    string studentName; 
    cout << "Enter student name: "; 
    getline(cin, studentName); 
    
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
    cout << "Enter scores (separated by space): "; 
    string scoresLine; 
    getline(cin, scoresLine); 
    
    istringstream iss(scoresLine); 
    int score; 
    int count = 0; 
    
    while (iss >> score) { // Читаємо кожне число з потоку по черзі
        if (student->addScore(subjectName, score) == 0) { 
            count++; 
        } else { 
            cout << "Error adding score: " << score << "\n"; 
        }
    }
    
    cout << "Added " << count << " scores to " << subjectName << "\n"; 

void addScoreMenu() {
    cout << "--- Add Score to Student ---\n";
    string name;
    cout << "Enter student name: ";
    getline(cin, name);

    Student* s = findStudentByName(name);
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

    s->subjects[subChoice - 1].scores.push_back(score);
    cout << "Score added successfully!\n";
}