#include "db.h"
#include "ui.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Student {
    string name;
    int age;
};

vector<Student> students; 

void addStudentMenu() {
    Student s;

    cout << "\n=== Add New Student ===\n";
    cout << "Enter name: ";
    getline(cin, s.name);

    cout << "Enter age: ";
    cin >> s.age;
    cin.ignore(); 

    students.push_back(s);
    cout << " Student added successfully!\n";
}


