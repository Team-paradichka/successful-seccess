#pragma once
#include "db.h"

extern StudentDatabase db;
void AddScore(StudentDatabase& db);

// Тільки ті функції, які є в вашому коді
void showMainMenu();
void addStudentMenu(); 
void addScoreMenu();
void listStudentsMenu();