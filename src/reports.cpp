#include "report.h"

using namespace std;
#include <iostream>

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



// Реалізація функцій які відносяться до звітів буде тут
// Наприклад, реалізація функції GenerateReport()
// void GenerateReport() {
//     std::cout << "Report generated!" << std::endl;
// };
// зауважте що тип який повертає функція, аргументи які вона приймає, і її імʼя мають відповідати оголошенню в report.h

