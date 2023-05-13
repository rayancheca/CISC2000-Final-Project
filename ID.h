/*
              Name: Rayan Checa
        Assignment: Final
	      Due Date: 12/05/2023	       
              File: ID.h
*/

#ifndef ID_H
#define ID_H

#include <string>

using namespace std;

// Declare the ID class
class ID {
private:
    // Declare private members for the ID_number and full_ID
    int ID_number;
    string full_ID;

public:
    // Declare the default constructor
    ID();

    // Declare a constructor with a prefix and a number
    ID(const string &prefix, int number);

    // Declare getters
    int getID_number() const;
    string getFull_ID() const;

    // Declare setters
    void setID_number(int number);
    void setFull_ID(const string &id);
};

#endif // ID_H
