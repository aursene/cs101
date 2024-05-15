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

class bigfour : public bigthree
{
public:
  int press{10};

  bigfour(std::string c_fname, std::string c_lname, int c_benchpress, int c_deadlift, int c_squat, int c_press)
  {
    fname = c_fname;
    lname = c_lname;
    benchpress = c_benchpress;
    deadlift = c_deadlift;
    squat = c_squat;
    press = c_press;
  }

  void display()
  {
    std::cout << '\n'
              << fname << " " << lname << "'s big three lifts: \n"
              << "bench press: " << benchpress << "lbs"
              << "\tdeadlift: " << deadlift << "lbs"
              << "\tsquat: " << squat << "lbs"
              << "\tpress: " << press << "lbs"
              << "\n";
  }
};

int main()
{
  bigthree Mark{"Mark", "Sosa", 135, 135, 135};
  Mark.display();

  cout << "\nChanging attributes...\n";
  Mark.lname = "Swolesa";
  Mark.benchpress = 105;
  Mark.deadlift = 95;
  Mark.squat = 405;

  Mark.display();

  cout << "\n\n";

  bigfour Braxton{"Braxton", "Beckman", 135, 135, 135, 135};
  Braxton.display();

  cout << "\nChanging attributes...\n";
  Braxton.lname = "Builtman";
  Braxton.benchpress *= 2;
  Braxton.deadlift *= 2;
  Braxton.squat *= 2;
  Braxton.press *= 2;

  Braxton.display();

  cout << "\n\n";
  return 0;
}
