#include "ui.h"

using namespace std;

// Реалізація функцій інтерфейсу програми буде тут
// Наприклад, реалізація функції ShowMenu()
// void ShowMenu() {
//     std::cout << "Hello!" << std::endl;
// };
// зауважте що тип який повертає функція, аргументи які вона приймає, і її імʼя мають відповідати оголошенню в ui.h

#include "db.h" 
#include <sstream> // Підключаємо бібліотеку для роботи з потоками рядків


void AddScore(StudentDatabase& db) { // Функція для додавання оцінок, приймає базу даних за посиланням
    string studentName; 
    cout << "Enter student name: "; 
    getline(cin, studentName); 
    
    Student* student = db.findStudentByName(studentName); // Шукаємо студента в базі даних за іменем
    if (student == nullptr) { 
        cout << "Student not found!\n"; 
        return; 
    }
    
    
    cout << "\nSelect subject:\n"; 
    for (size_t i = 0; i < SUBJECT_NAMES.size(); ++i) { 
        cout << i + 1 << " - " << SUBJECT_NAMES[i] << "\n"; 
    }
    
    int choice; 
    cout << "Your choice: "; 
    cin >> choice; 
    cin.ignore(); // Очищуємо буфер від символу нового рядка після числа
    
    if (choice < 1 || choice > static_cast<int>(SUBJECT_NAMES.size())) { 
        cout << "Invalid choice!\n"; 
        return; 
    }
    
    string subjectName = SUBJECT_NAMES[choice - 1]; 
    
    // Вводимо оцінки
    cout << "Enter scores (separated by space): "; 
    string scoresLine; 
    getline(cin, scoresLine); 
    
    istringstream iss(scoresLine); 
    int score; 
    int count = 0; 
    
    while (iss >> score) { // Читаємо кожне число з потоку по черзі
        if (student->addScore(subjectName, score) == 0) { 
            count++; 
        } else { 
            cout << "Error adding score: " << score << "\n"; 
        }
    }
    
    cout << "Added " << count << " scores to " << subjectName << "\n"; 
}