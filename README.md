 # CISC2000-Final-Project

The project aims to read course data from a file, perform various operations on the data, and generate output files based on the results. 

With this project, I aimed to read courses from the `CoursesFall2023.txt` file and:
1. Generate a professor list along with IDs. Save it to a file called `ProfessorsFall2023.txt`.
2. Produce a list of courses that overlap based on their timeslot using an overload for `==` indicating time overlap. This list is saved in the `OverlappingCourses.txt` file.

## Main Functionalities

The main functionalities of the program include:
- Reading course data from the `CoursesFall2023.txt` file.
- Generating a list of professors along with their IDs and saving it to the `ProfessorsFall2023.txt` file.
- Identifying and producing a list of courses that overlap based on their timeslots and saving it to the `OverlappingCourses.txt` file.
- Implementing classes and their respective member functions to represent university members, course information, names, and IDs.
- Implementing the concept of inheritance by creating a class hierarchy.
- Demonstrating the use of overloaded operators in the `Course` class to compare courses for equality and determine time overlap.
- Performing I/O operations on files, including reading from and writing to files.
- Using vectors and sets to store and manipulate data.
- Implementing accessor and mutator functions to access and modify class members.

## Features Demonstrated

Features demonstrated in the project:
- I/O parsing a file for course data with additional functionality (including time information): +1
- Inheritance (`UnivMember` class): +1
- Overloaded `operator==` and overloaded `operator<<` (in `Course` class): +2
- New dynamic objects (`Course` objects, `professors` vector): +2

## Compilation

As a warning, this code may not compile depending on which compiler you are using.
To compile this code, I have used this line of code in the command terminal on macOS:
g++ -std=c++11 -o UnivMemberDriver ID.cpp Name.cpp UnivMember.cpp Course.cpp UnivMemberDriver.cpp
