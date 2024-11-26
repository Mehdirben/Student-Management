# Student Database Management System

A simple Student Database Management System implemented in C++.

## Overview

This program provides functionalities for adding, displaying, searching, editing, and deleting student records stored in a file named `student.txt`. It leverages object-oriented programming concepts such as classes, inheritance, and file handling to manage and persist student data.

## Features

- **Add Record**: Input a student's name, course, and section, which are saved to `student.txt`.
- **List Records**: Displays all student records stored in `student.txt`.
- **Search Record**: Search for a student by their assigned number (position in the file).
- **Edit Record**: Modify a specific student's details by their assigned number.
- **Delete Record**: Remove a student record based on their assigned number.
- **Exit Program**: Safely terminates the program.

## How to Use

1. Compile the code using a C++ compiler (e.g., `g++`):
   ```bash
   g++ -o student_management student_management.cpp
   ```
2. Run the executable:
   ```bash
   ./student_management
   ```
3. Follow the on-screen menu options to manage student records.

## Menu Options

When you run the program, you will see the following menu:
```bash
Student Database Management System
1. Add Record
2. List Records
3. Search Record
4. Edit Record
5. Delete Record
0. Exit
Enter your choice:
```

**Add Record:** Input the student's name, course, and section to save the record.

**List Records:** View all existing student records.

**Search Record:** Search for a student by their assigned number.

**Edit Record:** Modify the details of a specific student.

**Delete Record:** Remove a student’s record.

**Exit:** Exit the program.

## File Structure

The program reads from and writes to a file named `student.txt` in the current working directory. Each line in the file represents a student's record in the format:
```bash
Name Course Section
```
Example:
```bash
John Physics A1
Jane Math B2
```
## Classes

**`Person` (Base Class)**

- **Methods:**
  - `ShowData()`: Displays all student records.
  - `SearchRecord()`: Searches for a student by their number.
  - `DeleteRecord()`: Deletes a student record by their number.
 
**`Student` (Derived Class)**

- **Attributes**:
  - `string cours`: Course of the student.
  - `string section`: Section of the student.
    
- **Methods:**
  - `AddRecord()`: Adds a new student record.
  - `entrer()`: Collects user input and calls `AddRecord`.
  - `EditRecord()`: Edits an existing student record.

## Error Handling

- If the `student.txt` file does not exist or cannot be opened, the program displays an error message and continues running.
- Input validation ensures that users cannot search, edit, or delete a record with an invalid number.

## Dependencies

- `<iostream>`: For input/output operations.
- `<fstream>`: For file handling.
- `<string>`: For string manipulation.
- `<vector>`: For dynamic storage of records.
