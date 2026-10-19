
# Exam Timetable Scheduling Using Graph Colouring

## 1. Project Overview

Exam Timetable Scheduling using Graph Colouring is a C++ application that generates an exam timetable while ensuring that no two courses with common students are scheduled in the same time slot.

The project represents courses as vertices in an undirected graph. An edge connects two courses if at least one student is enrolled in both courses. Graph colouring is then used to assign exam slots to courses without conflicts.

The program uses a **backtracking graph colouring algorithm** to find the minimum number of exam slots required.

## 2. Aim

To design and implement an efficient exam timetable scheduling system using graph colouring that prevents examination clashes between courses sharing students while minimizing the total number of exam slots.

## 3. Problem Statement

In an educational institution, multiple courses must be assigned examination time slots. Students may enroll in multiple courses, so scheduling two courses with common students at the same time creates a clash.

The objective is to assign time slots to all courses such that:

- No two courses with common students receive the same time slot.
- Every course is assigned exactly one time slot.
- The total number of time slots is minimized.

## 4. Objectives

- Represent courses and their conflicts using an undirected graph.
- Accept course enrolment information from the user.
- Construct the conflict graph automatically.
- Apply graph colouring using backtracking.
- Determine the minimum number of examination time slots.
- Display course conflicts and the final timetable.

## 5. Technologies Used

| Technology | Purpose |
|---|---|
| C++ | Implementation language |
| STL vectors | Store graph adjacency lists and colours |
| STL algorithms | Sort and remove duplicate entries |
| Graph data structure | Represent course conflicts |
| Backtracking | Find a valid minimum-colour assignment |

## 6. Graph Representation

The conflict graph is represented as an adjacency list.

- **Vertex:** Represents a course.
- **Edge:** Represents a conflict between two courses.
- **Colour:** Represents an examination time slot.
- **Adjacent vertices:** Must receive different colours.

For example, if a student is enrolled in courses C1, C2 and C3, the program adds edges between every pair of those courses.

```text
       C1
      /  \
     /    \
    C2----C3
```

This triangle means C1, C2 and C3 cannot share an examination slot. Therefore, at least three slots are required for these courses.

## 7. Algorithm

1. Start the program.
2. Read the number of courses and students.
3. For each student, read the courses in which they are enrolled.
4. Connect every pair of courses taken by the same student.
5. Remove duplicate edges from the graph.
6. Start with one available colour.
7. Assign colours to courses using backtracking.
8. Check that no adjacent courses share the same colour.
9. If a valid assignment is impossible, increase the number of available colours and try again.
10. Stop when a valid assignment is found.
11. Display the course conflicts, assigned examination slots and minimum number of slots.
12. End the program.

## 8. How Backtracking Works

Backtracking explores possible colour assignments for courses one at a time.

For each course:

1. Try an available colour.
2. Check whether any neighbouring course already has that colour.
3. If the colour is valid, assign it and process the next course.
4. If a later assignment fails, undo the current assignment and try another colour.
5. If all courses receive valid colours, the assignment succeeds.

The program tries colour limits from 1 to the total number of courses. The first successful limit gives the chromatic number, which is the minimum number of exam slots required.

## 9. How to Compile and Run

### Prerequisites

- A C++ compiler such as GCC or MinGW.
- A terminal or command prompt.
- The source file `graph-color.cpp`.

### Compilation

```bash
g++ -std=c++17 graph-color.cpp -o graph-color
```

### Run on Windows PowerShell

```powershell
.\graph-color.exe
```

### Run on Linux or macOS

```bash
./graph-color
```

## 10. Sample Input

Consider four courses and three students.

```text
Enter number of courses: 4
Enter number of students: 3

Enter number of courses taken by Student 1: 3
Enter course numbers (1 to 4): 1 2 3

Enter number of courses taken by Student 2: 2
Enter course numbers (1 to 4): 2 4

Enter number of courses taken by Student 3: 2
Enter course numbers (1 to 4): 3 4
```

## 11. Sample Output

```text
===== COURSE CONFLICTS =====
Course C1 conflicts with: C2 C3
Course C2 conflicts with: C1 C3 C4
Course C3 conflicts with: C1 C2 C4
Course C4 conflicts with: C2 C3

===== FINAL EXAM TIMETABLE =====
Course C1 -> Exam Slot 1
Course C2 -> Exam Slot 2
Course C3 -> Exam Slot 3
Course C4 -> Exam Slot 1

Minimum number of exam slots required: 3

No two courses with common students are scheduled in the same slot.
```

*Note: The precise colour assignment can vary with the course ordering. The minimum number of slots for this input is three.*

## 12. Time Complexity

Let:

- `V` be the number of courses (vertices).
- `E` be the number of conflict edges.

### Graph construction

For a student enrolled in `k` distinct courses, the program examines every pair of courses, requiring O(k²) time. Across all students, construction takes O(Σ kᵢ²), plus sorting and duplicate removal.

### Graph colouring

For a fixed limit of `m` colours, backtracking has a worst-case upper bound of O(m^V × (V + E)) using adjacency-list conflict checks as implemented.

The program tries limits from 1 to V. A loose overall upper bound is O(V^(V+1) × (V + E)).

Graph colouring is an NP-hard problem in general, so execution time can increase significantly as the number of courses grows.

### Space complexity

The graph and colour array require O(V + E) space. The recursive search uses up to O(V) additional stack space.

## 13. Applications

- College and university examination scheduling.
- Conflict-free classroom timetabling.
- University course scheduling.
- Meeting scheduling when participants have overlapping commitments.
- Resource allocation where conflicting activities cannot occur simultaneously.

## 14. Advantages

- Automatically identifies examination conflicts.
- Prevents courses sharing students from being scheduled together.
- Finds a minimum-slot solution for the constructed graph.
- Accepts enrolment information interactively.
- Uses a clear graph representation and backtracking strategy.

## 15. Limitations

- Backtracking can be slow for large graphs.
- The program minimizes time slots but does not allocate rooms.
- It does not consider instructor availability, room capacity, exam duration or student preferences.
- The input assumes valid course enrolment data.

## 16. Future Scope

- Add room allocation and room-capacity constraints.
- Consider instructor availability and examination durations.
- Develop a graphical user interface for timetable management.
- Store student enrolment data in a database.
- Add heuristic algorithms for faster scheduling on larger datasets.

## 17. Conclusion

The project demonstrates how graph colouring can solve the examination scheduling problem. Courses are represented as vertices, and conflicts are represented as edges. The backtracking algorithm assigns different colours to adjacent vertices and searches for the minimum number of colours required.

This approach produces a conflict-free timetable and demonstrates the practical application of graph theory, recursion and backtracking in a real-world scheduling problem.
