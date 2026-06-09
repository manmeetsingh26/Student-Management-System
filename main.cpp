#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int choice;

    string studentNames[100];
    int rollNumbers[100];
    float attendance[100];
    float marks[100];
    int studentCount = 0;

    // Load saved student records
    ifstream inputFile("students.txt");

    while (inputFile >> studentNames[studentCount]
                     >> rollNumbers[studentCount]
                     >> attendance[studentCount]
                     >> marks[studentCount]) {
        studentCount++;
    }

    inputFile.close();

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Update Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                if (studentCount < 100) {
                    cout << "Enter Student Name: ";
                    cin >> studentNames[studentCount];

                    cout << "Enter Roll Number: ";
                    cin >> rollNumbers[studentCount];

                    cout << "Enter Attendance Percentage: ";
                    cin >> attendance[studentCount];

                    cout << "Enter Marks: ";
                    cin >> marks[studentCount];

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
                        cout << "Attendance: " << attendance[i] << "%" << endl;
                        cout << "Marks: " << marks[i] << endl;
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
                        cout << "Attendance: " << attendance[i] << "%" << endl;
                        cout << "Marks: " << marks[i] << endl;

                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student not found.\n";
                }

                break;
            }

            case 4: {
                int deleteRoll;
                bool found = false;

                cout << "Enter Roll Number to Delete: ";
                cin >> deleteRoll;

                for (int i = 0; i < studentCount; i++) {
                    if (rollNumbers[i] == deleteRoll) {

                        for (int j = i; j < studentCount - 1; j++) {
                            studentNames[j] = studentNames[j + 1];
                            rollNumbers[j] = rollNumbers[j + 1];
                            attendance[j] = attendance[j + 1];
                            marks[j] = marks[j + 1];
                        }

                        studentCount--;

                        cout << "Student deleted successfully.\n";
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student not found.\n";
                }

                break;
            }

            case 5: {
                int updateRoll;
                bool found = false;

                cout << "Enter Roll Number to Update: ";
                cin >> updateRoll;

                for (int i = 0; i < studentCount; i++) {
                    if (rollNumbers[i] == updateRoll) {
                        cout << "Enter New Student Name: ";
                        cin >> studentNames[i];

                        cout << "Enter New Roll Number: ";
                        cin >> rollNumbers[i];

                        cout << "Enter New Attendance Percentage: ";
                        cin >> attendance[i];

                        cout << "Enter New Marks: ";
                        cin >> marks[i];

                        cout << "Student record updated successfully.\n";
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student not found.\n";
                }

                break;
            }

            case 6: {
                // Save all records before exit
                ofstream outputFile("students.txt");

                for (int i = 0; i < studentCount; i++) {
                    outputFile << studentNames[i] << " "
                               << rollNumbers[i] << " "
                               << attendance[i] << " "
                               << marks[i] << endl;
                }

                outputFile.close();

                cout << "Student records saved successfully.\n";
                cout << "Thank you for using Student Management System.\n";
                break;
            }

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
