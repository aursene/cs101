#include "employee.h"
#include <iostream>
using namespace std;

employee::employee()
{
  cout << "Created!\n";
}

string employee::getFirst()
{
  return fname;
}

void employee::getLast()
{
  cout << lname << endl;
}

string employee::toString()
{
  string output;
  output = "Name: " + lname + ", " + fname;
  return output;
}
