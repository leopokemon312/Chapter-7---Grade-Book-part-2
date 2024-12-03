// Chapter 7 - Grade Book part 2.
// This program calculates the average test score for five students, excluding the lowest score.
// It uses arrays to store student names, test scores, and letter grades.
// The user inputs the students' names and their test scores.
// Input validation ensures test scores are between 0 and 100.

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Constants for the number of students and tests
    const int NUM_STUDENTS = 5;
    const int NUM_TESTS = 4;

    // Arrays to store student names, test scores, and letter grades
    string names[NUM_STUDENTS];
    double scores[NUM_STUDENTS][NUM_TESTS];
    char letterGrades[NUM_STUDENTS];

    // Input: Get student names and test scores
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Enter the name of student " << (i + 1) << ": ";
        cin >> names[i];

        cout << "Enter four test scores for " << names[i] << ":\n";
        for (int j = 0; j < NUM_TESTS; j++) {
            do {
                cout << "Test " << (j + 1) << ": ";
                cin >> scores[i][j];
                if (scores[i][j] < 0 || scores[i][j] > 100) {
                    cout << "Invalid score! Please enter a score between 0 and 100.\n";
                }
            } while (scores[i][j] < 0 || scores[i][j] > 100);
        }
    }

    // Process: Calculate average scores (excluding the lowest score) and determine letter grades
    for (int i = 0; i < NUM_STUDENTS; i++) {
        double sum = 0, minScore = scores[i][0];

        // Find the sum of scores and identify the lowest score
        for (int j = 0; j < NUM_TESTS; j++) {
            sum += scores[i][j];
            if (scores[i][j] < minScore) {
                minScore = scores[i][j];
            }
        }

        // Exclude the lowest score from the sum
        sum -= minScore;
        double average = sum / (NUM_TESTS - 1);

        // Determine letter grade based on average
        if (average >= 90) {
            letterGrades[i] = 'A';
        }
        else if (average >= 80) {
            letterGrades[i] = 'B';
        }
        else if (average >= 70) {
            letterGrades[i] = 'C';
        }
        else if (average >= 60) {
            letterGrades[i] = 'D';
        }
        else {
            letterGrades[i] = 'F';
        }
    }

    // Output: Display student names, average scores, and letter grades
    cout << "\nGrade Book:\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
        double sum = 0, minScore = scores[i][0];

        // Recalculate sum and lowest score for display
        for (int j = 0; j < NUM_TESTS; j++) {
            sum += scores[i][j];
            if (scores[i][j] < minScore) {
                minScore = scores[i][j];
            }
        }

        sum -= minScore;
        double average = sum / (NUM_TESTS - 1);

        cout << "Student: " << names[i]
            << ", Average Score (lowest dropped): " << average
            << ", Letter Grade: " << letterGrades[i] << endl;
    }

    return 0;
}
