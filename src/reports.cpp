#include "report.h"
#include "db.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

extern StudentDatabase db;


void printStudentAverage() {
    std::string name;
    std::cout << "Enter student name: ";
    std::getline(std::cin >> std::ws, name);

    Student* student = db.findStudentByName(name);

    if (!student) {
        std::cout << "Student '" << name << "' not found.\n";
        return;
    }

    double average = calculateAverageScore(student->subjects);

    if (average == 0) {
        std::cout << "Student '" << name << "' has no grades yet.\n";
        return;
    }

    std::cout << "Student " << student->name
              << " average is: " << average << "\n";
}