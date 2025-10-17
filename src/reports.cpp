#include "report.h"
#include "db.h"
#include <iostream>
#include <vector>
#include <iomanip> 
#include <cmath>
#include <string>
using namespace std;


void printStudentAverage() {
    std::string name;
    std::cout << "Enter student name: ";
    std::getline(std::cin >> std::ws, name);

    Student* student = db.findStudentByName(name);

    if (!student) {
        std::cout << "Student '" << name << "' not found.\n";
        return;
    }

    double average = calculateAverageScore(student->subjects);

    if (average == 0) {
        std::cout << "Student '" << name << "' has no grades yet.\n";
        return;
    }

    std::cout << "Student " << student->name
              << " average is: " << average << "\n";
}


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

#include "db.h"
#include <iostream>
#include <vector>
#include <iomanip> 
#include <cmath>

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

void printGroupAverage() {
    const auto& students = db.getAllStudents();

    if (students.empty()) {
        std::cout << "There is no students in database.\n";
        return;
    }

    std::vector <Subject> subjects;

    for (const auto& student : students) {
        subjects.insert(subjects.end(), student.subjects.begin(), student.subjects.end());
    }

    double groupAverage = calculateAverageScore(subjects);

    if (std::abs(groupAverage) < 1e-3) {
        std::cout << "None has a grade.\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Group average: " << groupAverage << std::endl;
}

// -----------------------------------------------------------
// Task 8: Print All Students List
// Мета: Створити загальний список групи для викладача.
// Очікуваний результат: У консоль виводиться пронумерований список імен усіх студентів, що є в базі.
// -----------------------------------------------------------

void printAllStudentsList()
{
    const auto& students = db.getAllStudents();

    if (students.empty())
    {
        std::cout << "\nThe student database is currently empty." << std::endl;
    }
    else
    {
        for (int i = 0; i < students.size(); i++)
        {
            std::cout << (i + 1) << ". " << students[i].name << std::endl;
        }
    }
}
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

void printStudentScores() {

  std::string studentName;
  cout << "Enter student's name\n>>> ";
  cin >> studentName;

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

