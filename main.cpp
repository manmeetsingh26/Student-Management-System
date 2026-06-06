#include <iostream>
using namespace std;

int main() {
    int choice;

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
                cout << "Add Student feature coming soon.\n";
                break;

            case 2:
                cout << "View Students feature coming soon.\n";
                break;

            case 3:
                cout << "Search Student feature coming soon.\n";
                break;

            case 4:
                cout << "Thank you for using Student Management System.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
