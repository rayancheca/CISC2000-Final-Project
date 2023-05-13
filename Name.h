/*
              Name: Rayan Checa
        Assignment: Final
	      Due Date: 12/05/2023	       
              File: Name.h
*/

#ifndef NAME_H
#define NAME_H

#include <string>

using namespace std;

// Name class declaration
class Name {
private:
    string fname; // First name
    string lname; // Last name

public:
    // Default constructor
    Name();

    // Constructor that takes a full name (last, first)
    Name(const string& full_name);

    // Getter for first name
    string getFirstName() const;

    // Getter for last name
    string getLastName() const;

    // Function to print full name (first last)
    void printName() const;

    // toString method
    string toString() const;
};

#endif // NAME_H
