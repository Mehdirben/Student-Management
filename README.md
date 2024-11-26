Student Database Management System
Overview
This program is a basic Student Database Management System written in C++. It provides essential functionalities such as adding, viewing, searching, editing, and removing student records stored in a file called student.txt.

The system utilizes object-oriented programming principles, including classes, inheritance, and file handling, to efficiently manage and store student data.

Features
Add Record

Users can add new student records by entering the student's name, course, and section, which are saved in the student.txt file.
List Records

Displays all the student records stored in student.txt.
Search Record

Allows users to search for a student by their assigned number (corresponding to their position in the file).
Edit Record

Provides the option to modify the details of an existing student record based on their assigned number.
Delete Record

Removes a specific student record identified by their number.
Exit Program

Safely terminates the application.
How to Use
Compile the program using a C++ compiler (e.g., g++):

bash


g++ -o student_management student_management.cpp
Run the executable:

bash


./student_management
Follow the on-screen menu options to interact with the system and manage student records.

Menu Options
After launching the program, a menu is displayed with the following options:

text


Student Database Management System
1. Add Record
2. List Records
3. Search Record
4. Edit Record
5. Delete Record
0. Exit
Enter your choice:
Add Record: Enter the student's name, course, and section to save their information.
List Records: View all the current student records stored in the file.
Search Record: Find a student's information by their assigned number.
Edit Record: Update the details of a specific student.
Delete Record: Remove a student’s information from the file.
Exit: Exit the program safely.
File Structure
The program interacts with a file named student.txt, located in the current working directory. Each line in the file represents a student record in the following format:

text


Name Course Section
Example of file contents:

text


John Physics A1
Jane Math B2
Classes
Person (Base Class)

Methods:
ShowData(): Displays all student records.
SearchRecord(): Searches for a student by their assigned number.
DeleteRecord(): Deletes a record based on the assigned number.
Student (Derived Class)

Inherits from the Person class.
Attributes:
string course: Stores the course name.
string section: Stores the student’s section.
Methods:
AddRecord(): Adds a new student record to the file.
entrer(): Collects user input and invokes AddRecord().
EditRecord(): Edits an existing student record.
Error Handling
If the student.txt file is missing or cannot be opened, an error message is displayed, but the program continues to run.
Input validation is implemented to ensure users cannot search, edit, or delete records using invalid numbers.
Dependencies
This program relies on the following standard C++ libraries:

<iostream>: For input and output operations.
<fstream>: For reading from and writing to files.
<string>: For handling strings.
<vector>: For dynamically managing collections of records.
