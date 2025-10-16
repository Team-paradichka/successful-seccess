#include "report.h"
#include <iostream>
#include <iomanip> 
#include <vector>
#include <cmath>

extern StudentDatabase db;

void printGroupAverage() {
    const auto& students = db.getAllStudents();

    if (students.empty()) {
        std::cout << "There is no students in database.\n";
        return;
    }

    std::vector <Subject> subjects;

    for (const auto& student : students) {
        subjects.insert(subjects.begin(), student.subjects.begin(), student.subjects.end());
    }

    double groupAverage = calculateAverageScore(subjects);

    if (std::abs(groupAverage) < 1e-3) {
        std::cout << "Noone has a grade.\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Group average: " << groupAverage << std::endl;
}

