#include "ui.h"
#include "report.h"
#include <iostream>

using namespace std;

void showTeacherMenu() {
    int choice = 0;

while (true) {
    cout << "\nTeacher Main Menu" << endl;
    cout << "1. Add new student" << endl;
    cout << "2. Find student by name" << endl;
    cout << "3. Print all students list" << endl;
    cout << "4. Print top students report" << endl;
    cout << "5. Print scholarship list" << endl;
    cout << "0. Exit to main menu" << endl;
    cout << "Choose an option: ";
    cin >> choice;

    switch (choice) {
    case 1:
    cout << "\nEnter student name: ";
    {
        string name;
        cin.ignore();
        getline(cin, name);
        db.addNewStudent(name);
        cout << "Student added successfully.\n";
    }
    break;

    case 2:
    cout << "\nEnter student name to find: ";
    {
        string name;
        cin.ignore();
        getline(cin, name);
        Student* student = db.findStudentByName(name);
        if (student) {
            cout << "Found student: " << student->name << "\n";}
        else {
            cout << " Student not found.\n";}
    }
        break;

    case 3:
        printAllStudents(); 
        break;

    case 4:
        printTopStudents(); 
        break;

    case 5:
        printScholarshipList(); 
        break;

    case 0:
            cout << "Returning to main menu...\n";
          return;

    default:
            cout << "Unknown option. Please try again.\n";
        break;
        }
    }
}