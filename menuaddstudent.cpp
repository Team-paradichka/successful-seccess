
extern StudentDatabase db;

void addStudentScoreMenu() {
    string studentName;
    string subjectName;
    int score;

    cout << "Enter student's name: ";
    getline(cin, studentName);

    Student* student = db.findStudentByName(studentName);
    if (!student) {
        cout << "Error: student '" << studentName << "' not found.\n";
        return;
    }

    cout << "Enter subject name: ";
    getline(cin, subjectName);

    cout << "Enter score: ";
    cin >> score;
    cin.ignore();


    int result = student->addScore(subjectName, score);

    if (result == 0) {
        cout << " Score " << score << " in subject '" << subjectName 
             << "' added to " << student->name << ".\n";
    } else {
        cout << "⚠️ Subject '" << subjectName 
             << "' not found for student.\n";
    }
}
