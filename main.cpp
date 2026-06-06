#include <iostream>
#include <string>
using namespace std;

int main() {
    int choice;

    string studentNames[100];
    int rollNumbers[100];
    int studentCount = 0;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                if (studentCount < 100) {

                    cout << "Enter Student Name: ";
                    cin >> studentNames[studentCount];

                    cout << "Enter Roll Number: ";
                    cin >> rollNumbers[studentCount];

                    studentCount++;

                    cout << "Student added successfully.\n";

                } else {
                    cout << "Student limit reached.\n";
                }
                break;

            case 2:
                if (studentCount == 0) {

                    cout << "No student records found.\n";

                } else {

                    cout << "\n===== Student Records =====\n";

                    for (int i = 0; i < studentCount; i++) {

                        cout << "\nStudent " << i + 1 << endl;
                        cout << "Name: " << studentNames[i] << endl;
                        cout << "Roll Number: " << rollNumbers[i] << endl;
                    }
                }
                break;

            case 3: {
                int searchRoll;
                bool found = false;

                cout << "Enter Roll Number to Search: ";
                cin >> searchRoll;

                for (int i = 0; i < studentCount; i++) {

                    if (rollNumbers[i] == searchRoll) {

                        cout << "\n===== Student Found =====\n";
                        cout << "Name: " << studentNames[i] << endl;
                        cout << "Roll Number: " << rollNumbers[i] << endl;

                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student not found.\n";
                }

                break;
            }

            case 4:
                cout << "Thank you for using Student Management System.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
