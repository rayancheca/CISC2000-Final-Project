/*
              Name: Rayan Checa
        Assignment: Final
	      Due Date: 12/05/2023	       
              File: Course.h
*/

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

using namespace std;

class Course {
private:
    string subject;
    string courseNumber;
    string section;
    string description;
    int hours;
    int CRN;
    string term;
    string instructor;
    vector<string> meetingDays;
    string startTime;
    string endTime;

public:
    // Default constructor
    Course();

    // Constructor with parameters
    Course(const string &subject, const string &courseNumber, const string &section,
           const string &description, int hours, int CRN, const string &term,
           const string &instructor, const vector<string> &meetingDays,
           const string &startTime, const string &endTime);

    // Getters
    string getSubject() const;
    string getCourseNumber() const;
    string getSection() const;
    string getDescription() const;
    int getHours() const;
    int getCRN() const;
    string getTerm() const;
    string getInstructor() const;
    vector<string> getMeetingDays() const;
    string getStartTime() const;
    string getEndTime() const;

    // Setters
    void setSubject(const string &subject);
    void setCourseNumber(const string &courseNumber);
    void setSection(const string &section);
    void setDescription(const string &description);
    void setHours(int hours);
    void setCRN(int CRN);
    void setTerm(const string &term);
    void setInstructor(const string &instructor);
    void setMeetingDays(const vector<string> &meetingDays);
    void setStartTime(const string &startTime);
    void setEndTime(const string &endTime);

    // Check if two courses overlap
    bool overlaps(const Course &other) const;

    // Overloaded operator== declaration
    bool operator==(const Course &other) const;
};

#endif // COURSE_H

