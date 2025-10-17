#include "db.h"
#include <algorithm>
#include <cctype>

const std::vector<std::string> SUBJECT_NAMES = {
    "Math", "Science", "History", "Art", "Physical Education"
};

int Student::addScore(const std::string& subjectName, int score) {
    for (auto& subject : subjects) {
        if (subject.name == subjectName) {
            subject.scores.push_back(score);
            return 0;
        }
    }
    return 1;
}

void StudentDatabase::addNewStudent(const std::string& name) {
    std::string lowered_name = name;
    std::transform(lowered_name.begin(), lowered_name.end(), lowered_name.begin(), [](unsigned char c){ return std::tolower(c); });
    Student new_student;
    new_student.name = lowered_name;

    for (const auto& subjectName : SUBJECT_NAMES) {
        Subject subject;
        subject.name = subjectName;
        new_student.subjects.push_back(subject);
    }
    students_.push_back(new_student);
}

Student* StudentDatabase::findStudentByName(const std::string& name) {
    std::string lowered_name = name;
    std::transform(lowered_name.begin(), lowered_name.end(), lowered_name.begin(), [](unsigned char c){ return std::tolower(c); });
    for (auto& student : students_) {
        if (student.name == lowered_name) {
            return &student;
        }
    }
    return nullptr;
}

const std::vector<Student>& StudentDatabase::getAllStudents() const {
    return students_;
}
