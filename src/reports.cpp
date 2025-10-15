#include "report.h"
#include <iostream>
#include <vector>
using namespace std;

extern StudentDatabase db;

float calculateStudentAverage(const Student& student) {
    int totalScore = 0;
    int scoreCount = 0;
    for (const auto& subject : student.subjects) {
        for (int score : subject.scores) {
            totalScore += score;
            scoreCount++;
        }
    }
    if (scoreCount == 0) {
        return 0.0f;
    }
    return static_cast<float>(totalScore) / scoreCount;
}

void printExpulsionList() {
    vector<Student> expulsion_candidates;

    for (const auto& student : db.getAllStudents()) {
        float avgScore = calculateStudentAverage(student);
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
                      << ", Average Score: " << calculateStudentAverage(student) << endl;
        }
    }
 cout << "-------------------------------------------\n";
}
