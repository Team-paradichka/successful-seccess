#include "report.h"
#include <iomanip>

using namespace std;

// Реалізація функцій які відносяться до звітів буде тут
// Наприклад, реалізація функції GenerateReport()
// void GenerateReport() {
//     std::cout << "Report generated!" << std::endl;
// };
// зауважте що тип який повертає функція, аргументи які вона приймає, і її імʼя мають відповідати оголошенню в report.h


void printStudentScores(const std::string& studentName, StudentDatabase& db) {
  Student* student = db.findStudentByName(studentName);

  if (student == nullptr) {
    cout << "ERROR: student name is invalid." << endl;
    return;
  }

  std::cout << "Student scores: " << student->name << std::endl;

  for (const auto& subject : student->subjects) {
    std::cout << std::left << std::setw(20) << subject.name << ": ";

    if (subject.scores.empty()) {
      std::cout << "No scores recorded." << std::endl;
    }
    else {
      for (int score : subject.scores) {
        std::cout << score << " | ";
      }
      std::cout << std::endl;
    }
  }
}
