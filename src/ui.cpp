#include "ui.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Subject {
    string name;
    vector<int> scores;
};

struct Student {
    string name;
    vector<Subject> subjects;
};

vector<Student> students;

Student* findStudentByName(const string& name) {
    for (auto& s : students) {
        if (s.name == name)
            return &s;
    }
    return nullptr;
}

void showMainMenu() {
    while (true) {
        cout << "\n=== STUDENT MANAGEMENT SYSTEM ===\n";
        cout << "1. Add Student\n";
        cout << "2. Add Score to Student\n"; 
        cout << "3. List All Students\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addStudentMenu();
                break;
            case 2:
                addScoreMenu();
                break;
            case 3:
                listStudentsMenu();
                break;
            case 0:
                cout << "Goodbye!\n";
                return;
            default:
                cout << "Invalid option! Please try again.\n";
        }
    }
}

void addStudentMenu() {
    cout << "--- Add New Student ---\n";
    string name;
    cout << "Enter student name: ";
    getline(cin, name);

    Student s;
    s.name = name;
    students.push_back(s);

    cout << "Student '" << name << "' added successfully!\n";
}

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

void listStudentsMenu() {
    cout << "--- Students List ---\n";
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }
    
    for (const auto& s : students) {
        cout << "Student: " << s.name << "\n";
        if (!s.subjects.empty()) {
            for (const auto& sub : s.subjects) {
                cout << "  " << sub.name << " scores: ";
                if (sub.scores.empty()) {
                    cout << "No scores";
                } else {
                    for (int sc : sub.scores)
                        cout << sc << " ";
                }
                cout << endl;
            }
        } else {
            cout << "  No subjects/scores\n";
        }
        cout << "------------------------\n";
    }
}