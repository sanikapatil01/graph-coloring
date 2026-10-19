
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n; // Number of courses
vector<vector<int>> graph;
vector<int> colour;

// Check whether a colour can be assigned to a course
bool isSafe(int course, int c) {
    for (int neighbour : graph[course]) {
        if (colour[neighbour] == c) {
            return false;
        }
    }
    return true;
}

// Backtracking graph colouring
bool graphColouring(int course, int maxColours) {
    if (course == n) {
        return true;
    }

    for (int c = 1; c <= maxColours; c++) {
        if (isSafe(course, c)) {
            colour[course] = c;

            if (graphColouring(course + 1, maxColours)) {
                return true;
            }

            colour[course] = 0;
        }
    }

    return false;
}

int main() {
    int students;

    cout << " EXAM TIMETABLE SCHEDULING \n";

    cout << "Enter number of courses: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of courses must be positive.\n";
        return 1;
    }

    cout << "Enter number of students: ";
    cin >> students;

    if (students < 0) {
        cout << "Number of students cannot be negative.\n";
        return 1;
    }

    graph.resize(n);
    colour.assign(n, 0);

    // Read each student's course enrolments
    for (int i = 0; i < students; i++) {
        int count;

        cout << "\nEnter number of courses taken by Student "
             << i + 1 << ": ";
        cin >> count;

        if (count < 0 || count > n) {
            cout << "Invalid number of courses.\n";
            return 1;
        }

        vector<int> enrolled(count);

        cout << "Enter course numbers (1 to " << n << "): ";

        for (int j = 0; j < count; j++) {
            cin >> enrolled[j];

            if (enrolled[j] < 1 || enrolled[j] > n) {
                cout << "Invalid course number.\n";
                return 1;
            }

            enrolled[j]--; // Convert to zero-based index
        }

        // Sort and remove duplicate enrolments
        sort(enrolled.begin(), enrolled.end());
        enrolled.erase(
            unique(enrolled.begin(), enrolled.end()),
            enrolled.end()
        );

        // Connect every pair of courses taken by this student
        for (int j = 0; j < (int)enrolled.size(); j++) {
            for (int k = j + 1;
                 k < (int)enrolled.size(); k++) {
                int u = enrolled[j];
                int v = enrolled[k];

                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
    }

    // Remove duplicate edges from adjacency lists
    for (int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());

        graph[i].erase(
            unique(graph[i].begin(), graph[i].end()),
            graph[i].end()
        );
    }

    // Display conflict graph
    cout << "\n COURSE CONFLICTS \n";

    for (int i = 0; i < n; i++) {
        cout << "Course C" << i + 1 << " conflicts with: ";

        if (graph[i].empty()) {
            cout << "None";
        } else {
            for (int neighbour : graph[i]) {
                cout << "C" << neighbour + 1 << " ";
            }
        }

        cout << '\n';
    }

    // Find the minimum number of exam slots
    int minSlots = 0;

    for (int m = 1; m <= n; m++) {
        fill(colour.begin(), colour.end(), 0);

        if (graphColouring(0, m)) {
            minSlots = m;
            break;
        }
    }

    // Display final timetable
    cout << "\n===== FINAL EXAM TIMETABLE =====\n";

    for (int i = 0; i < n; i++) {
        cout << "Course C" << i + 1
             << " -> Exam Slot " << colour[i] << '\n';
    }

    cout << "\nMinimum number of exam slots required: "
         << minSlots << '\n';

    return 0;
}
