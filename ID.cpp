/*
              Name: Rayan Checa
        Assignment: Final
	      Due Date: 12/05/2023	       
              File: ID.cpp
*/

#include "ID.h"

using namespace std;

// Initialize a static variable to store the current ID number
static int currentNumber = 10000000;

// Define the default constructor
ID::ID() 
{
    // Set the ID_number and increment the currentNumber
    setID_number(currentNumber++);

    // Set the full_ID as 'A' concatenated with the ID_number
    setFull_ID("A" + to_string(getID_number()));
}

// Define the constructor with a prefix and a number
ID::ID(const string &prefix, int number) 
{
    setID_number(number);
    setFull_ID(prefix + to_string(getID_number()));
}

// Define the getter for ID_number
int ID::getID_number() const 
{
    return ID_number;
}

// Define the getter for full_ID
string ID::getFull_ID() const 
{
    return full_ID;
}

// Define the setter for ID_number
void ID::setID_number(int number) 
{
    ID_number = number;
}

// Define the setter for full_ID
void ID::setFull_ID(const string &id) 
{
    full_ID = id;
}
