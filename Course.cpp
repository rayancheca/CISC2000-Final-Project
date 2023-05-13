/*
              Name: Rayan Checa
        Assignment: Final
	      Due Date: 12/05/2023	       
              File: Course.cpp
*/

#include "Course.h"
#include <algorithm>

// Default constructor
Course::Course() : subject(""), courseNumber(""), section(""),
                   description(""), hours(0), CRN(0), term(""),
                   instructor(""), startTime(""), endTime("") {}

// Constructor with parameters
Course::Course(const string &subject, const string &courseNumber, const string &section,
               const string &description, int hours, int CRN, const string &term,
               const string &instructor, const vector<string> &meetingDays,
               const string &startTime, const string &endTime)
    : subject(subject), courseNumber(courseNumber), section(section), description(description),
      hours(hours), CRN(CRN), term(term), instructor(instructor),
      meetingDays(meetingDays), startTime(startTime), endTime(endTime) {}

// Getters
string Course::getSubject() const { return subject; }
string Course::getCourseNumber() const { return courseNumber; }
string Course::getSection() const { return section; }
string Course::getDescription() const { return description; }
int Course::getHours() const { return hours; }
int Course::getCRN() const { return CRN; }
string Course::getTerm() const { return term; }
string Course::getInstructor() const { return instructor; }
vector<string> Course::getMeetingDays() const { return meetingDays; }
string Course::getStartTime() const { return startTime; }
string Course::getEndTime() const { return endTime; }

// Setters
void Course::setSubject(const string &subject) { this->subject = subject; }
void Course::setCourseNumber(const string &courseNumber) { this->courseNumber = courseNumber; }
void Course::setSection(const string &section) { this->section = section; }
void Course::setDescription(const string &description) { this->description = description; }
void Course::setHours(int hours) { this->hours = hours; }
void Course::setCRN(int CRN) { this->CRN = CRN; }
void Course::setTerm(const string &term) { this->term = term; }
void Course::setInstructor(const string &instructor) { this->instructor = instructor; }
void Course::setMeetingDays(const vector<string> &meetingDays) { this->meetingDays = meetingDays; }
void Course::setStartTime(const string &startTime) { this->startTime = startTime; }
void Course::setEndTime(const string &endTime) { this->endTime = endTime; }

// Check if two courses overlap
bool Course::overlaps(const Course &other) const {
    // Check if the meeting days overlap
    for (const auto &day : this->meetingDays) {
        if (find(other.meetingDays.begin(), other.meetingDays.end(), day) != other.meetingDays.end()) {
            // If they do, check if the meeting times overlap
            if ((this->startTime >= other.startTime && this->startTime < other.endTime) ||
                (this->endTime > other.startTime && this->endTime <= other.endTime) ||
                (this->startTime <= other.startTime && this->endTime >= other.endTime)) {
                return true;
            }
        }
    }
    return false;
}



// Overloaded operator== implementation
bool Course::operator==(const Course &other) const {
    return this->CRN == other.CRN;
}
