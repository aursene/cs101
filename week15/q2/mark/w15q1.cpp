/*
    @Mark Sosa      04/29/24    
    Week 15 Q1      Base Class
    Objective:      Create Base Class .h file with at least three attributes, 
                    full constructor, and display function. Create .cpp that will create object,
                    display defaults, make changes to attributes and display again.
    Commands:       
*/
#include "bigthree.h"
#include <iostream>

using namespace std;

int main () 
{
    bigthree Mark {"Mark", "Sosa", 135, 135, 135};
    Mark.display();
    
    cout << "\nChanging attributes...\n";
    Mark.lname = "Swolesa";
    Mark.benchpress = 105;
    Mark.deadlift = 95;
    Mark.squat = 405;

    Mark.display();

    cout << "\n\n";
    return 0;
}
