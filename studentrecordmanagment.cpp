#include <iostream>   // For input (cin) and output (cout)
#include <string>     // To use string data type
#include <vector>     // To use dynamic arrays (vector)

using namespace std;

// Structure to store student information
struct Student { 
    // A structure is used to group related variables
    string name;     // Student's name
    string rollNo;   // Student's roll number
    string branch;   // Student's branch
    string course;   // Student's course
    string emailId;  // Student's email address
};

// Vector to store all student records
// Vector is a dynamic array, can grow or shrink during runtime
vector<Student> students;

// Function to add a student
void addStudent() {
    Student s;       // Create a temporary student object
    cin.ignore();    // Clear the input buffer before getline

    // Take student details from user
    cout << "Enter Name   : "; getline(cin, s.name);
    cout << "Enter RollNo : "; getline(cin, s.rollNo);
    cout << "Enter Branch : "; getline(cin, s.branch);
    cout << "Enter Course : "; getline(cin, s.course);
    cout << "Enter Email  : "; getline(cin, s.emailId);

    students.push_back(s);  // Add the student object to the vector
    cout << "Student added successfully!\n\n";
}

// Function to display all students
void displayStudents() {
    if (students.empty()) { // Check if vector is empty
        cout << "No student records found.\n\n";
        return; // Exit function if no records
    }

    // Loop through the vector and display all student records
    for (int i = 0; i < students.size(); i++) {
        cout << "Record " << i + 1 << ":\n";
        cout << "Name   : " << students[i].name << endl;
        cout << "RollNo : " << students[i].rollNo << endl;
        cout << "Branch : " << students[i].branch << endl;
        cout << "Course : " << students[i].course << endl;
        cout << "Email  : " << students[i].emailId << endl;
        cout << "-------------------------\n";
    }
}

// Function to search a student by RollNo
void searchStudent() {
    if (students.empty()) { // If no records, display message
        cout << "No student records found.\n\n";
        return;
    }

    string roll;       // Variable to store roll number to search
    cin.ignore();      // Clear input buffer
    cout << "Enter Roll No to Search: ";
    getline(cin, roll);

    bool found = false; // Flag to check if student exists

    // Loop through all students
    for (auto &s : students) {
        if (s.rollNo == roll) { // Compare roll number
            // If found, display student details
            cout << "Student Found:\n";
            cout << "Name   : " << s.name << endl;
            cout << "Branch : " << s.branch << endl;
            cout << "Course : " << s.course << endl;
            cout << "Email  : " << s.emailId << endl;
            found = true;
            break; // Stop searching after finding
        }
    }

    if (!found) { // If student not found
        cout << "Student record not found.\n";
    }
    cout << "\n";
}

// Function to delete a student by RollNo
void deleteStudent() {
    if (students.empty()) { // If no records, display message
        cout << "No student records found.\n\n";
        return;
    }

    string roll;     // Variable to store roll number to delete
    cin.ignore();    // Clear input buffer
    cout << "Enter Roll No to Delete: ";
    getline(cin, roll);

    bool found = false; // Flag to check if student exists

    // Loop through vector
    for (int i = 0; i < students.size(); i++) {
        if (students[i].rollNo == roll) { // Compare roll number
            students.erase(students.begin() + i); // Remove student from vector
            cout << "Student record deleted successfully!\n\n";
            found = true;
            break;
        }
    }

    if (!found) { // If student not found
        cout << "Student record not found.\n\n";
    }
}

// Main function - program execution starts here
int main() {
    int choice; // Variable to store menu choice

    while (true) { // Infinite loop for menu
        // Display menu
        cout << "===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) { // Select menu option
            case 1: // Add student
                addStudent();
                break;
            case 2: // Display all students
                displayStudents();
                break;
            case 3: // Search student
                searchStudent();
                break;
            case 4: // Delete student
                deleteStudent();
                break;
            case 5: // Exit program
                cout << "Exiting program...\n";
                exit(0);
            default: // Invalid choice
                // Using if-else inside default
                if (choice < 1) {
                    cout << "Choice cannot be less than 1!\n\n";
                } else if (choice > 5) {
                    cout << "Choice cannot be more than 5!\n\n";
                } else {
                    cout << "Invalid input!\n\n";
                }
        }
    }

    return 0; // End of program
}



