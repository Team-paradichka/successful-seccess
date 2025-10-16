#include "report.h"
#include "ui.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
};

vector<Student> students;

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

int main() {
    while (true) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. List Students\n";
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
                cout << "--- Students List ---\n";
                for (const auto& s : students)
                    cout << s.name << endl;
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid option!\n";
        }
    }
}
