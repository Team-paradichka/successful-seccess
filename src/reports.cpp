#include "report.h"
using namespace std;

// Реалізація функцій які відносяться до звітів буде тут
// Наприклад, реалізація функції GenerateReport()
// void GenerateReport() {
//     std::cout << "Report generated!" << std::endl;
// };
// зауважте що тип який повертає функція, аргументи які вона приймає, і її імʼя мають відповідати оголошенню в report.h

void printHonorStudents(){
    cout << "============ Honor Students ============" << endl;

    for(const auto& student : db.getAllStudents()){
        double total_sum = 0.0;
        double subject_count = 0;
        double average_score = 0.0;

        for(const auto& subject : student.subjects){
            for (int score: subject.scores){
                total_sum += score;
                subject_count ++;
            }
        }

        if (subject_count > 0){
            average_score = total_sum / subject_count;
            if (average_score >= 88.0){
                cout << student.name << ". Average score: " << average_score << endl;
            }
        }
    }

    cout << "=====================================" << endl;
    
}