#include "report.h"

using namespace std;

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

