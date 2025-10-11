#pragma once
#include <string>
#include <vector>
#include <iostream>

extern const std::vector<std::string> SUBJECT_NAMES;

struct Subject {
    std::string name;
    std::vector<int> scores;
};

class Student {
public:
    std::string name;
    std::vector<Subject> subjects;

    int addScore(const std::string& subjectName, int score);
};

class StudentDatabase {
private:
    std::vector<Student> students_;

public:
    void addNewStudent(const std::string& name);
    Student* findStudentByName(const std::string& name);
    const std::vector<Student>& getAllStudents() const;
};