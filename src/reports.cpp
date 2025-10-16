#include "report.h"

using namespace std;

#include "db.h"
#include <iostream>

void printMyGrades(StudentDatabase& db) {
    const std::string myName = "Mark"; // твій студент

    Student* me = db.findStudentByName(myName);
    if (!me) {
        std::cout << "Student not found!\n";
        return;
    }

    std::cout << "Grades for " << myName << ":\n";
    for (const auto& subject : me->subjects) {
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

