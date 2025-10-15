#include "ui.h"

using namespace std;

// Реалізація функцій інтерфейсу програми буде тут
// Наприклад, реалізація функції ShowMenu()
// void ShowMenu() {
//     std::cout << "Hello!" << std::endl;
// };
// зауважте що тип який повертає функція, аргументи які вона приймає, і її імʼя мають відповідати оголошенню в ui.h


void studentMenu() {
    int choise;
    do {
        std::cout << "\nChoose an option as a Student:\n";
        std::cout << "1 - Show all my grades\n";
        std::cout << "2 - Add a new score\n"; 
        std::cout << "0 - Back to main menu\n";
        std::cin >> choise;
        if (choise == 1) {
            //showStudentGrade();  P.s: Зняти коментар коли функція буде готова
        }
        else if (choise == 2) {  
            //AddScore();   P.s: Зняти коментар коли функція буде готова
        }
        else if (choise == 0) {
            //mainMenu();   P.s: Зняти коментар коли функція буде готова
            break;
        }
        else { 
            std::cout << "Choose a valid option...\n";
        }
    } while (choise != 0); //Цикл працює поки користувач не вийде в меню входу
    
}
