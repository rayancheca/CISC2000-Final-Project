/*
              Name: Rayan Checa
        Assignment: Final
	      Due Date: 12/05/2023	       
              File: UnivMember.h
*/

#ifndef UNIVMEMBER_H
#define UNIVMEMBER_H

#include "ID.h"
#include "Name.h"
#include <string>

using namespace std;

// Declare the UnivMember class
class UnivMember {
private:
    ID UnivID; // University ID
    Name UnivName; // University Name
    string Role; // Role in the university (Prof, Student or Admin)

public:
    // Default constructor
    UnivMember();

    // Constructor with parameters
    UnivMember(const string &role, const string &full_name);

    // Getters
    ID getUnivID() const;
    Name getUnivName() const;
    string getRole() const;

    // Setters
    void setUnivID(const ID &id);
    void setUnivName(const Name &name);
    void setRole(const string &role);

    // Print UnivMember information
    void printUnivMember() const;

    // toString method
    string toString() const;
};

#endif // UNIVMEMBER_H

