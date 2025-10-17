#include "report.h"

using namespace std;

// Реалізація функцій які відносяться до звітів буде тут
// Наприклад, реалізація функції GenerateReport()
// void GenerateReport() {
//     std::cout << "Report generated!" << std::endl;
// };
// зауважте що тип який повертає функція, аргументи які вона приймає, і її імʼя мають відповідати оголошенню в report.h

void printBestAndWorstStudents() {
    auto students = db.getAllStudents();
    if (students.empty()) {
        cout << "No students available." << endl;
        return;
    }

    double maxAverage = calculateAverageScore(students[0].subjects);
    double minAverage = calculateAverageScore(students[0].subjects);
    std::string bestStudent = students[0].name;
    std::string worstStudent = students[0].name;

    for (const auto& student : students) {
        double avg = calculateAverageScore(student.subjects);
        if (avg > maxAverage) {
            maxAverage = avg;
            bestStudent = student.name;
        }
        if (avg < minAverage) {
            minAverage = avg;
            worstStudent = student.name;
        }
    }

    cout << "Best Student: " << bestStudent << " with average score: " << maxAverage << endl;
    cout << "Worst Student: " << worstStudent << " with average score: " << minAverage << endl;
}