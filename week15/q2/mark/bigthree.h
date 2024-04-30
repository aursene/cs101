#pragma once
#include <iostream>

class bigthree
{
public:
    std::string fname = "Mark";
    std::string lname = "Default";
    int benchpress = 10;
    int deadlift = 10;
    int squat = 10;
    
    //constructors
    bigthree (){
    }
    bigthree (std::string c_fname, std::string c_lname, int c_benchpress, int c_deadlift, int c_squat)
    {
        fname = c_fname;
        lname = c_lname;
        benchpress = c_benchpress;
        deadlift = c_deadlift;
        squat = c_squat;
    }

    // functions
    void display()
    {
        std::cout << '\n' << fname << " " << lname << "'s big three lifts: \n"
             << "bench press: " << benchpress << "lbs"
             << "\tdeadlift: " << deadlift << "lbs"
             << "\tsquat: " << squat << "lbs" << "\n";
    }

};
