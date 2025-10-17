#pragma once
#include "db.h"

extern StudentDatabase db;

// Файл який містить функції які відносяться до звітів
// Тут ви оголошуєте функції які будуть використовуватись для створення звітів
// Приклад оголошення функції void GenerateReport();
// Зауважте що реалізація цих функцій буде в окремому файлі src/report.cpp
double calculateAverageScore(const std::vector<Subject>& subjects);
//TODO Task 5 Print My Grades

//TODO: Task 6 Print student Grades

//TODO: Task 8 Print All Students List

//TODO: Task 9 Calculate student Average

//TODO: Task 10 Print student Average

//TODO: Task 11 Print Group Averages

//TODO: Task 12 Find AND Print Scholarship Students

//TODO Task 13 Find And Print Honor Students List

//TODO Task 14 Find And Print Expulsion List

void printBestAndWorstStudents();