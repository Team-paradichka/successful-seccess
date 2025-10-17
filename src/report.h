#pragma once
#include "db.h"

extern StudentDatabase db;

void printAllStudentsList();

// Файл який містить функції які відносяться до звітів
// Тут ви оголошуєте функції які будуть використовуватись для створення звітів
// Приклад оголошення функції void GenerateReport();
// Зауважте що реалізація цих функцій буде в окремому файлі src/report.cpp



//TODO Task 2 Print grades of any student
void printStudentScores();


//TODO Task 5 Print My Grades
void printMyGrades();

//TODO: Task 6 Print student Grades

//TODO: Task 9 Calculate student Average
double calculateAverageScore(const std::vector<Subject>& subjects);
//TODO: Task 10 Print student Average

//TODO: Task 11 Print Group Averages

void printGroupAverage();
double calculateAverageScore(const std::vector<Subject>& subjects);

//TODO: Task 12 Find AND Print Scholarship Students
void get_scholarship_student();
//TODO Task 13 Find And Print Honor Students List
void printHonorStudents();


//TODO Task 14 Find And Print Expulsion List

void printExpulsionList();
