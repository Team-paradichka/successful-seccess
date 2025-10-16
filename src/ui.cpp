#include "ui.h"
#include "report.h"
#include <iostream>
using namespace std;

void showTeacherMenu() {
    int choice = 0;

    while (true) {
        cout << "\n===== Teacher Main Menu =====" << endl;
        cout << "1. Вивести оцінки студента" << endl;
        cout << "2. Вивести список усіх зареєстрованих студентів" << endl;
        cout << "3. Додати нового студента" << endl;
        cout << "4. Знайти найкращого та найгіршого студента (за середнім балом)" << endl;
        cout << "5. Показати середній бал усієї групи" << endl;
        cout << "6. Показати список студентів, які отримують стипендію (avg > 70)" << endl;
        cout << "7. Порахувати кількість відмінників (avg > 88)" << endl;
        cout << "8. Вивести список студентів на відрахування (avg < 50)" << endl;
        cout << "0. Вийти до головного меню" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            printStudentScores();          
            break;
        case 2:
            printAllStudents();
            break;
        case 3:
            db.addNewStudent();               
            break;
        case 4:
            printBestAndWorstStudents();
            break;
        case 5:
            printGroupAverage();
            break;
        case 6:
            printScholarshipList();
            break;
        case 7:
            countExcellentStudents();
            break;
        case 8:
            printExpulsionList();
            break;
        case 0:
            cout << "Повернення до головного меню...\n";
            return;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
    }
}