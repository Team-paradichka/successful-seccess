#include <iostream>
#include "ui.h"

using namespace std;

void main_menu()
{
    cout << "Welcome to ProStudentHelper!\nTo continue please choose one of the following options:" << endl;
    cout << "1 - Continue as a student\n2 - Continue as a teacher\n0 - Quit the program" << endl;
    int roleChoice;
    cin >> roleChoice;
    switch(roleChoice)
    {
        case 1:
            studentMenu();
        case 2:
            showTeacherMenu();
        case 0:
            abort();
        default:
            cout << "Please, choose an apropriate option." << endl;
            main_menu();
    }
    
}