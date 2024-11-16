
# STUDENT MANAGEMENT SYSTEM

*  Overview
This program is a simple " Student Management System "  written in C++ that allows users to manage student records. The program enables adding, viewing, searching, and deleting student records stored in a file. It uses basic file handling to persist data.



*  Features
1.  Add Student Record**  
   - Allows users to input a new student's details.
   - The data is stored in the `stuData.txt` file.
   - Records include:
     - Roll Number
     - Name
     - Father's Name
     - Address

2.  View All Student Records  
   - Displays all stored student records.
   - Reads data from the `stuData.txt` file and formats it for display.

3.  Search Student Record  
   - Searches for a student by their roll number.
   - Displays the student's details if found.

4.  Delete Student Record 
   - Deletes a specific student record based on roll number.
   - Updates the `stuData.txt` file by removing the selected record.

5.  User-Friendly Menu  
   - Interactive menu for easy navigation.
   - Allows users to perform multiple operations or exit the program.



##  Code Structure

*   Classes and Functions

1.  Class: `StudentManager`
This class contains all the functions needed for managing student records.

* Functions:
1.  'void addStudent()'
   - Prompts the user to enter student details.
   - Appends the details to the file `stuData.txt`.
   - Handles errors if the file cannot be opened.

2.  `void viewStudents()`
   - Reads all student records from `stuData.txt`.
   - Displays each record in a readable format.
   - Checks if there are no records and notifies the user.

3.  `void searchStudent()`
   - Prompts the user to enter a roll number.
   - Searches the file for a matching roll number.
   - Displays the record if found; otherwise, notifies the user.

4.  `void deleteStudent()`
   - Prompts the user to enter the roll number of the record to delete.
   - Reads all records into a vector, excluding the one to be deleted.
   - Overwrites the file with the updated records.
   - Notifies the user about the deletion status.

5.  `void displayMenu()` 
   - Displays an interactive menu.
   - Calls the appropriate function based on the user's choice.
   - Loops until the user chooses to exit.


* Menu Options
1:  Add Student Record**
  - Enter the student's details as prompted.
2:  View All Student Records**
  - Displays all records stored in `stuData.txt`.
3:  Search Student Record**
  - Enter a roll number to search for a specific student.
4:  Delete Student Record**
  - Enter a roll number to delete a specific student record.
5:  Exit**
  - Exits the program.


*  Error Handling

1.  File Access Errors:
   - If the file cannot be opened for reading or writing, the program displays an error message.

2.  Invalid Roll Numbers:
   - When searching or deleting, if the roll number is not found, the user is notified.



##  Future Enhancements
-  Update Student Records:** Add functionality to modify existing records.
-  Data Encryption:** Secure student data with basic encryption.
-  GUI Integration:** Build a graphical user interface for easier interaction.
-  Database Integration:** Use a database (e.g., SQLite) for better performance and scalability.



This is all about the code hope you get the overview about this code !!!  :)
