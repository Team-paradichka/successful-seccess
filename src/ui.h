#pragma once
#include "db.h"

extern StudentDatabase db;
void AddScore(StudentDatabase& db);


// Файл який містить функції які відносяться до інтерфейсу програми
// Тут ви оголошуєте функції які будуть використовуватись для взаємодії з користувачем
// Приклад оголошення функції void ShowMenu();
// Зауважте що реалізація цих функцій буде в окремому файлі src/ui.cpp

//TODO: Task 1 Main Menu

//TODO: Task 2 Student Menu
void studentMenu();

//TODO: Task 3 Teacher Menu
void showTeacherMenu();
//TODO: Task 4 Add student Menu

//TODO: Task 5 Add score Menu

// Тільки ті функції, які є в вашому коді
void showMainMenu();
void addStudentMenu(); 
void addScoreMenu();
void listStudentsMenu();
