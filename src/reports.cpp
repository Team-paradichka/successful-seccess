#include "report.h"
#include <iostream>
#include <iomanip> 
#include <vector>
#include <cmath>

using namespace std;

void printMyGrades() {
    auto me = db.getAllStudents()[0];

    std::cout << "Grades for " << me.name << ":\n";
    for (const auto& subject : me.subjects) {
        std::cout << subject.name << ": ";
        if (subject.scores.empty()) {
            std::cout << "no grades\n";
        } else {
            for (int score : subject.scores)
                std::cout << score << " ";
            std::cout << "\n";
        }
    }
}

void printGroupAverage() {
    const auto& students = db.getAllStudents();

    if (students.empty()) {
        std::cout << "There is no students in database.\n";
        return;
    }

    std::vector <Subject> subjects;

    for (const auto& student : students) {
        subjects.insert(subjects.end(), student.subjects.begin(), student.subjects.end());
    }

    double groupAverage = calculateAverageScore(subjects);

    if (std::abs(groupAverage) < 1e-3) {
        std::cout << "None has a grade.\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Group average: " << groupAverage << std::endl;
}

// -----------------------------------------------------------
// Task 8: Print All Students List
// Мета: Створити загальний список групи для викладача.
// Очікуваний результат: У консоль виводиться пронумерований список імен усіх студентів, що є в базі.
// -----------------------------------------------------------

void printAllStudentsList()
{
    const auto& students = db.getAllStudents();

    if (students.empty())
    {
        std::cout << "\nThe student database is currently empty." << std::endl;
    }
    else
    {
        for (int i = 0; i < students.size(); i++)
        {
            std::cout << (i + 1) << ". " << students[i].name << std::endl;
        }
    }
}
// Реалізація функцій які відносяться до звітів буде тут
// Наприклад, реалізація функції GenerateReport()
// void GenerateReport() {
//     std::cout << "Report generated!" << std::endl;
// };
// зауважте що тип який повертає функція, аргументи які вона приймає, і її імʼя мають відповідати оголошенню в report.h


