#include "report.h"
#include <iostream>
#include <iomanip> 

extern StudentDatabase db;

void printGroupAverage() {
    const auto& students = db.getAllStudents();

    if (students.empty()) {
        std::cout << "There is no students in database.\n";
        return;
    }

    double totalAverage = 0.0;
    int studentsWithGrades = 0;

    for (const auto& student : students) {
        double sum = 0.0;
        int count = 0;

        for (const auto& subject : student.subjects) {
            for (int score : subject.scores) {
                sum += score;
                count++;
            }
        }

        if (count > 0) {
            double avg = sum / count;
            totalAverage += avg;
            studentsWithGrades++;
        }
    }

    if (studentsWithGrades == 0) {
        std::cout << "Noone has a grade.\n";
        return;
    }

    double groupAverage = totalAverage / studentsWithGrades;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Group average: " << groupAverage << std::endl;
}

