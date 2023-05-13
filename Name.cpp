/*
              Name: Rayan Checa
        Assignment: Final
	      Due Date: 12/05/2023	       
              File: Name.cpp
*/

#include "Name.h"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

// Helper function to remove leading and trailing spaces
string trim(const string &s) 
{
    auto start = s.begin();
    auto end = s.end();
    while (start != end && isspace(*start))
        ++start;
    while (start != end && isspace(*(end - 1)))
        --end;
    return string(start, end);
}

// Default constructor implementation
Name::Name() : fname("First"), lname("Last") {}

// Constructor implementation that takes a full name (last, first)
Name::Name(const string& full_name) {
    size_t comma_index = full_name.find(",");
    lname = trim(full_name.substr(0, comma_index));
    fname = trim(full_name.substr(comma_index + 1));
}

// Getter implementation for first name
string Name::getFirstName() const 
{
    return fname;
}

// Getter implementation for last name
string Name::getLastName() const 
{
    return lname;
}

// Function implementation to print full name (first last)
void Name::printName() const 
{
    cout << fname << " " << lname << endl;
}

// toString method
string Name::toString() const
{
    return fname + " " + lname;
}
