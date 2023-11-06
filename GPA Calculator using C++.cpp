#include <iostream>
#include <string>

using namespace std;

// Function to convert letter grades to grade points
double getGradePoint(const string& grade) {
    if (grade == "A+" || grade == "a+") {
        return 4.0;
    } else if (grade == "A" || grade == "a") {
        return 4.0;
    } else if (grade == "A-" || grade == "a-") {
        return 3.7;
    } else if (grade == "B+" || grade == "b+") {
        return 3.3;
    } else if (grade == "B" || grade == "b") {
        return 3.0;
    } else if (grade == "B-" || grade == "b-") {
        return 2.7;
    } else if (grade == "C+" || grade == "c+") {
        return 2.3;
    } else if (grade == "C" || grade == "c") {
        return 2.0;
    } else if (grade == "C-" || grade == "c-") {
        return 1.7;
    } else if (grade == "D+" || grade == "d+") {
        return 1.3;
    } else if (grade == "D" || grade == "d") {
        return 1.0;
    } else if (grade == "E" || grade == "e") {
        return 0.0;
    } else {
        return 0.0; // Invalid grade
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    for (int i = 1; i <= numCourses; i++) {
        double credits;
        string grade;
        
        cout << "Enter the number of credits for course " << i << ": ";
        cin >> credits;
        
        cout << "Enter the letter grade for course " << i << " (A+/A/A-/B+/B/B-/C+/C/C-/D+/D/E): ";
        cin >> grade;

        double gradePoint = getGradePoint(grade);

        if (gradePoint == 0.0) {
            cout << "Invalid grade entered. Please enter a valid grade." << endl;
            i--; // Decrement i to re-enter the grade for the same course
        } else {
            totalCredits += credits;
            totalGradePoints += credits * gradePoint;
        }
    }

    if (totalCredits > 0) {
        double gpa = totalGradePoints / totalCredits;
        cout << "Cumulative Grade Point Average (CGPA): " << gpa << endl;
    } else {
        cout << "No valid course grades entered. CGPA cannot be calculated." << endl;
    }

    return 0;
}
