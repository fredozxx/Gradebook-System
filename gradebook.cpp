#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void sortGrades(string names[], int grades[], int count);
int searchStudent(string names[], int count, string searchName);
void displayStats(int grades[], int count);

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Create arrays for names and grades
    string names[numStudents];
    int grades[numStudents];

    // Input student names and grades
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter student name: ";
        cin >> names[i];
        cout << "Enter " << names[i] << "'s grade: ";
        cin >> grades[i];
    }

    // Sort the grades
    sortGrades(names, grades, numStudents);

    // Display sorted grades
    cout << "\nSorted Grades:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << names[i] << ": " << grades[i] << endl;
    }

    // Search for a student's grade
    string searchName;
    cout << "\nEnter student name to search: ";
    cin >> searchName;
    int index = searchStudent(names, numStudents, searchName);
    if (index != -1) {
        cout << searchName << "'s grade: " << grades[index] << endl;
    } else {
        cout << searchName << " not found.\n";
    }

    // Display class statistics
    displayStats(grades, numStudents);

    return 0;
}

// Function to sort grades and names in ascending order
void sortGrades(string names[], int grades[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (grades[i] > grades[j]) {
                // Swap grades
                int tempGrade = grades[i];
                grades[i] = grades[j];
                grades[j] = tempGrade;

                // Swap corresponding names
                string tempName = names[i];
                names[i] = names[j];
                names[j] = tempName;
            }
        }
    }
}

// Function to search for a student's grade
int searchStudent(string names[], int count, string searchName) {
    for (int i = 0; i < count; i++) {
        if (names[i] == searchName) {
            return i;
        }
    }
    return -1;
}

// Function to calculate and display class statistics
void displayStats(int grades[], int count) {
    int sum = 0;
    int highest = grades[0];
    int lowest = grades[0];

    for (int i = 0; i < count; i++) {
        sum += grades[i];
        if (grades[i] > highest) highest = grades[i];
        if (grades[i] < lowest) lowest = grades[i];
    }

    double average = static_cast<double>(sum) / count;
    cout << "\nClass Statistics:\n";
    cout << "Average Grade: " << average << endl;
    cout << "Highest Grade: " << highest << endl;
    cout << "Lowest Grade: " << lowest << endl;
}
