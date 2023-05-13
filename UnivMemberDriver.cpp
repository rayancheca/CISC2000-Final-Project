/*
              Name: Rayan Checa
        Assignment: Final
	      Due Date: 12/05/2023	       
              File: UnivMemberDriver.cpp
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include "UnivMember.h"
#include <iomanip>
#include "Course.h"

using namespace std;

int main() {
    // Read the input file
    ifstream inFile("CoursesFall2023.txt");
    string line;
    vector<string> professors;

    // Skip the header line
    getline(inFile, line);

    while (getline(inFile, line)) {
        // Find the position of the first double-quote character
        size_t firstQuote = line.find('"');

        // If the first double-quote character is found
        if (firstQuote != string::npos) {
            // Find the position of the second double-quote character
            size_t secondQuote = line.find('"', firstQuote + 1);

            // If the second double-quote character is found
            if (secondQuote != string::npos) {
                // Extract the professor's name and add it to the vector
                string professorName = line.substr(firstQuote + 1, secondQuote - firstQuote - 1);
                if (professorName != "TBD") {
                    professors.push_back(professorName);
                }
            }
        }
    }
    
    // Open the file again for the second read
    inFile.open("CoursesFall2023.txt");
    string courseLine;

    vector<Course> courses;

    // Skip the header line
    getline(inFile, courseLine);

    while (getline(inFile, courseLine)) {
        stringstream ss(courseLine);
        vector<string> data;
        string item;

        // Split the line into different data fields
        while (getline(ss, item, '\t')) {
            data.push_back(item);
        }

        // Extract the relevant information for a course
        string subject = data[0];
        string courseNumber = data[1];
        string section = data[2];
        string description = data[3];
        int hours = stoi(data[4]);
        int CRN = stoi(data[5]);
        string term = data[6];
        string instructor = data[7];

        // Extract the meeting days and times
        stringstream meetingDaysStream(data[9]);
        vector<string> meetingDays;
        string meetingDay;
        while (getline(meetingDaysStream, meetingDay, ',')) {
            meetingDays.push_back(meetingDay);
        }

        string startTime = data[10];
        string endTime = data[11];

        // Create a Course object and add it to the courses vector
        Course course(subject, courseNumber, section, description, hours, CRN, term,
                      instructor, meetingDays, startTime, endTime);
        courses.push_back(course);
    }

    inFile.close();

    // Find overlapping courses
    vector<Course> overlappingCourses;
    for (size_t i = 0; i < courses.size(); i++) {
        for (size_t j = i + 1; j < courses.size(); j++) {
            if (courses[i] == courses[j] && courses[i].overlaps(courses[j])) {
                overlappingCourses.push_back(courses[i]);
                overlappingCourses.push_back(courses[j]);
            }
        }
    }

    // Output the overlapping courses
    ofstream overlapOutFile("OverlappingCourses.txt");

    if (overlappingCourses.empty()) {
        overlapOutFile << "No overlapping courses found." << endl;
    } else {
       overlapOutFile << "Overlapping Courses:" << endl;
        for (const Course& course : overlappingCourses) {
            overlapOutFile << "Course: " << course.getSubject() << " " << course.getCourseNumber()
                    << " (Section " << course.getSection() << ")" << endl;
            overlapOutFile << "Instructor: " << course.getInstructor() << endl;
            overlapOutFile << "Meeting Times: " << course.getStartTime() << " - " << course.getEndTime() << endl;
            overlapOutFile << "--------------------------------------------" << endl;
        }
    }

    // Remove duplicate professor names
    set<string> uniqueProfessors(professors.begin(), professors.end());
    professors.assign(uniqueProfessors.begin(), uniqueProfessors.end());

    // Output the professor list with IDs
    ofstream outFile("ProfessorsFall2023.txt");

for (const string& profName : professors) {
    UnivMember p("Professor", profName);  // Add "Professor" as the role
    outFile << "Professor: " << left << setw(30) << p.getUnivName().toString()
            << "ID: " << p.getUnivID().getFull_ID() << "\n";
}

    outFile.close();

    return 0;
}

