#include "report.h"
#include "db.h"
#include <iostream>
#include <vector>

using namespace std;

extern StudentDatabase db;

void get_scholarship_student() {
    vector<Student> scholarship;
    int count = 0;
    double highavgscore = 70.0;
    const std::vector<Student>& students = db.getAllStudents();
    for (const Student& s : students) {
        double avg = calculateStudentAverage(s);
        if(avg >= highavgscore) {
            count++;
            std::cout << "Student: " << s.name << endl;
            scholarship.push_back(s);
            std::cout << "Average score: " << avg << endl;
        }
    }
    if (count <= 0) {
    std::cout << "There are no students who will have a scholarship." << endl;
    }
}
