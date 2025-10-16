#include "db.h"
#include "ui.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Subject {
    string name;
    vector<int> scores;
};

struct Student {
    string name;
    vector<Subject> subjects;
};

vector<Student> students;

Student* findStudentByName(const string& name) {
    for (auto& s : students) {
        if (s.name == name)
            return &s;
    }
    return nullptr;
}

void addScoreMenu() {
    cout << "--- Add Score to Student ---\n";
    string name;
    cout << "Enter student name: ";
    getline(cin, name);

    Student* s = findStudentByName(name);
    if (!s) {
        cout << "Error: student not found!\n";
        return;
    }

    cout << "Available subjects:\n";
    for (size_t i = 0; i < s->subjects.size(); i++) {
        cout << i + 1 << ". " << s->subjects[i].name << endl;
    }

    int subChoice;
    cout << "Choose subject number: ";
    cin >> subChoice;
    cin.ignore();

    if (subChoice < 1 || subChoice > (int)s->subjects.size()) {
        cout << "Invalid choice!\n";
        return;
    }

    int score;
    cout << "Enter score: ";
    cin >> score;
    cin.ignore();

    s->subjects[subChoice - 1].scores.push_back(score);
    cout << "Score added successfully!\n";
}

int main() {
 

    while (true) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Add Score\n";
        cout << "2. List Students and Scores\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addScoreMenu();
                break;
            case 2:
                cout << "--- Students List ---\n";
                for (const auto& s : students) {
                    cout << s.name << ":\n";
                    for (const auto& sub : s.subjects) {
                        cout << "  " << sub.name << " scores: ";
                        for (int sc : sub.scores)
                            cout << sc << " ";
                        cout << endl;
                    }
                }
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid option!\n";
        }
    }
}
