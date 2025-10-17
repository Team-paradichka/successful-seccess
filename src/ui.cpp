#include "ui.h"
#include "report.h"
#include <iostream>
using namespace std;

void showTeacherMenu() {
    int choice = 0;

    while (true) {
        cout << "\n===== Teacher Main Menu =====" << endl;
        cout << "1. Display a student's grades" << endl;
        cout << "2. Show the list of all registered students" << endl;
        cout << "3. Add a new student" << endl;
        cout << "4. Find the best and worst student (by average grade)" << endl;
        cout << "5. Show a student's average grade" << endl;
        cout << "6. Show the group's average grade" << endl;
        cout << "7. Show the list of students receiving a scholarship (avg > 70)" << endl;
        cout << "8. Count the number of excellent students (avg > 88)" << endl;
        cout << "9. Show the list of students subject to expulsion (avg < 50)" << endl;
        cout << "0. Return to the main menu" << endl;
        cout << "Your choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            printStudentScores();          
            break;
        case 2:
            printAllStudentsList();
            break;
        case 3:
            addStudentMenu();               
            break;
        case 4:
            printBestAndWorstStudents();
            break;
        case 5:
            printStudentAverage();
            break; 
        case 6:
            printGroupAverage();
            break;
        case 7:
            get_scholarship_student();
            break;
        case 8:
            printHonorStudents();
            break;
        case 9:
            printExpulsionList();
            break;
        case 0:
            mainMenu();
            return;
        default:
            cout << "Invalid choice. Try again\n";
            break;
        }
    }
}