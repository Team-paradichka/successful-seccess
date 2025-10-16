#include "report.h"
#include <iostream>
#include <vector>
using namespace std;

extern StudentDatabase db;

double calculateAverageScore(const std::vector<Subject>& subjects);

void printExpulsionList() {
    vector<Student> expulsion_candidates;

    for (const auto& student : db.getAllStudents()) {
        double avgScore = calculateAverageScore(student.subjects);
        if (avgScore > 0 && avgScore < 50.0f) {
            expulsion_candidates.push_back(student);
        }
    }

  cout << "\n--- Report: Expulsion List --- \n";
    if (expulsion_candidates.empty()) {
       cout << "No students are candidates for expulsion \n";
    } else {
        for (const auto& student : expulsion_candidates) {
             cout << "  - Name: " << student.name
                      << ", Average Score: " << calculateAverageScore(student.subjects) << endl;
        }
    }
 cout << "-------------------------------------------\n";
}
