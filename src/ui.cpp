#include "ui.h"
#include <iostream>
#include <string>
#include <vector>
#include "db.h" 
#include <sstream>
using namespace std;


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