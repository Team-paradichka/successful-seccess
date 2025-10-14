#include "report.h"
#include "db.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Глобальна база студентів, оголошена в main.cpp
extern StudentDatabase db;

// -----------------------------------------------------------
// Task 10: Print Student Average
// Функція запитує ім’я студента, знаходить його у базі,
// підраховує середній бал за всіма предметами та виводить його.
// -----------------------------------------------------------
void printStudentAverage() {
    std::string name;
    std::cout << "Enter student name: ";
    std::getline(std::cin >> std::ws, name); // Забезпечує коректне зчитування після cin >>

    // Пошук студента у базі
    Student* student = db.findStudentByName(name);

    if (!student) {
        std::cout << "Student '" << name << "' not found.\n";
        return;
    }

    double totalSum = 0.0;
    int totalCount = 0;

    // Обчислення середнього балу
    for (const auto& subject : student->subjects) {
        for (int score : subject.scores) {
            totalSum += score;
            totalCount++;
        }
    }

    if (totalCount == 0) {
        std::cout << "Student '" << name << "' has no grades yet.\n";
        return;
    }

    double average = totalSum / totalCount;

    std::cout << "Student " << student->name
              << " average is: " << average << "\n";
}
// Реалізація функцій які відносяться до звітів буде тут
// Наприклад, реалізація функції GenerateReport()
// void GenerateReport() {
//     std::cout << "Report generated!" << std::endl;
// };
// зауважте що тип який повертає функція, аргументи які вона приймає, і її імʼя мають відповідати оголошенню в report.h

