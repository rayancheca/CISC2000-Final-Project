/*
              Name: Rayan Checa
        Assignment: Final
	      Due Date: 12/05/2023	       
              File: UnivMember.cpp
*/

#include "UnivMember.h"
#include <iostream>

using namespace std;

// Default constructor
UnivMember::UnivMember() : Role("Unknown") {}

// Constructor with parameters
UnivMember::UnivMember(const string &role, const string &full_name) 
{
    setRole(role);
    setUnivName(Name(full_name)); // Create a Name object from full_name
}

// Getter for UnivID
ID UnivMember::getUnivID() const 
{
    return UnivID;
}

// Getter for UnivName
Name UnivMember::getUnivName() const 
{
    return UnivName;
}

// Getter for Role
string UnivMember::getRole() const 
{
    return Role;
}

// Setter for UnivID
void UnivMember::setUnivID(const ID &id) 
{
    UnivID = id;
}

// Setter for UnivName
void UnivMember::setUnivName(const Name &name) 
{
    UnivName = name;
}

// Setter for Role
void UnivMember::setRole(const string &role) 
{
    Role = role;
}

// Print UnivMember information
void UnivMember::printUnivMember() const 
{
    cout << getRole() << ": " << getUnivName().getLastName() << ", " << getUnivName().getFirstName() << endl;
    cout << "ID: " << getUnivID().getFull_ID() << endl << endl;
}


// toString method
string UnivMember::toString() const
{
    return getRole() + ": " + UnivName.toString() + ", ID: " + getUnivID().getFull_ID();
}
