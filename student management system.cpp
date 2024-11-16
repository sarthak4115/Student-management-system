#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class StudentManager {
    string rollNum, name, fName, address, search;
    fstream file;

public:
    void addStudent();
    void viewStudents();
    void searchStudent();
    void deleteStudent();
    void displayMenu();
};

void StudentManager::addStudent() {
    cout << "\n--- Add New Student Record ---\n";
    cout << "Enter Student Roll Number: ";
    getline(cin, rollNum);
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Student Father Name: ";
    getline(cin, fName);
    cout << "Enter Student Address: ";
    getline(cin, address);

    file.open("stuData.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << rollNum << "*" << name << "*" << fName << "*" << address << "\n";
        file.close();
        cout << "Student record added successfully!\n";
    } else {
        cout << "Error: Unable to open file for writing.\n";
    }
}

void StudentManager::viewStudents() {
    cout << "\n--- All Student Records ---\n";
    file.open("stuData.txt", ios::in);
    if (file.is_open()) {
        bool recordsFound = false;
        while (getline(file, rollNum, '*') &&
               getline(file, name, '*') &&
               getline(file, fName, '*') &&
               getline(file, address)) {
            recordsFound = true;
            cout << "\nStudent Roll Number: " << rollNum
                 << "\nStudent Name: " << name
                 << "\nStudent Father Name: " << fName
                 << "\nStudent Address: " << address << "\n";
        }
        file.close();
        if (!recordsFound) {
            cout << "No student records found.\n";
        }
    } else {
        cout << "Error: Unable to open file for reading.\n";
    }
}

void StudentManager::searchStudent() {
    cout << "\n--- Search Student Record ---\n";
    cout << "Enter Student Roll Number to Search: ";
    getline(cin, search);

    file.open("stuData.txt", ios::in);
    if (file.is_open()) {
        bool recordFound = false;
        while (getline(file, rollNum, '*') &&
               getline(file, name, '*') &&
               getline(file, fName, '*') &&
               getline(file, address)) {
            if (rollNum == search) {
                recordFound = true;
                cout << "\nStudent Roll Number: " << rollNum
                     << "\nStudent Name: " << name
                     << "\nStudent Father Name: " << fName
                     << "\nStudent Address: " << address << "\n";
                break;
            }
        }
        file.close();
        if (!recordFound) {
            cout << "No record found for Roll Number: " << search << "\n";
        }
    } else {
        cout << "Error: Unable to open file for reading.\n";
    }
}

void StudentManager::deleteStudent() {
    cout << "\n--- Delete Student Record ---\n";
    cout << "Enter Student Roll Number to Delete: ";
    getline(cin, search);

    vector<string> records;
    bool recordFound = false;

    file.open("stuData.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, rollNum, '*') &&
               getline(file, name, '*') &&
               getline(file, fName, '*') &&
               getline(file, address)) {
            if (rollNum == search) {
                recordFound = true;
            } else {
                records.push_back(rollNum + "*" + name + "*" + fName + "*" + address);
            }
        }
        file.close();
    } else {
        cout << "Error: Unable to open file for reading.\n";
        return;
    }

    if (recordFound) {
        file.open("stuData.txt", ios::out | ios::trunc); // Clear the file
        if (file.is_open()) {
            for (const auto& record : records) {
                file << record << "\n";
            }
            file.close();
            cout << "Record deleted successfully!\n";
        } else {
            cout << "Error: Unable to open file for writing.\n";
        }
    } else {
        cout << "No record found for Roll Number: " << search << "\n";
    }
}

void StudentManager::displayMenu() {
    char choice;
    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1 - Add Student Record\n";
        cout << "2 - View All Student Records\n";
        cout << "3 - Search Student Record\n";
        cout << "4 - Delete Student Record\n";
        cout << "5 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice) {
            case '1':
                addStudent();
                break;
            case '2':
                viewStudents();
                break;
            case '3':
                searchStudent();
                break;
            case '4':
                deleteStudent();
                break;
            case '5':
                cout << "Exiting the program. Goodbye!\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5');
}

int main() {
    StudentManager manager;
    manager.displayMenu();
    return 0;
}
