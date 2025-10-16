#include "report.h"

using namespace std;

void printHonorStudents(){
    cout << "============ Honor Students ============" << endl;

    for(const auto& student : db.getAllStudents()){
        double average_score = calculateAverageScore(const std::vector<Subject>& subjects);

        if (average_score >= 88.0){
                cout << student.name << ". Average score: " << average_score << endl;
            }
        
    }
    cout << "=====================================" << endl;
    
}