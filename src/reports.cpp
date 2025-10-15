#include "report.h"

using namespace std;

double calculateAverageScore(const std::vector<Subject>& subjects) {
    double sum = 0.0;
    int count = 0;

    for (const auto& subject : subjects) {
        for (int score : subject.scores) {
            sum += score;
            count++;
        }
    }

    if (count == 0) {
        return 0;
    }

    return sum / count;
}