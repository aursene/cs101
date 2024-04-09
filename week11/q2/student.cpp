#include "student.h"
#include <iostream>

using namespace std;

student::student()
{
  cout << "What is your name? ";
  cin >> name;
  cout << "What is your GPA? ";
  cin >> gpa;
  cout << endl;
}

void student::display()
{
  cout << "Your name is " << name << "\nYou have a " << getGpa() << " GPA"
       << "\nYou are taking " << getClasses();
}

bool student::approval(double cgpa)
{
  if (cgpa >= 3.0)
    return true;
  else
    return false;
}

double student::getGpa()
{
  return gpa;
}

void student::setGpa(double newGpa)
{
  gpa = newGpa;
}

string student::getName()
{
  return name;
}

string student::getClasses()
{
  string out{};
  if (classes.empty() == true)
    out = "no classes.";
  else
  {
    for (string i : classes)
    {
      out += i + (i == classes.back() ? "." : ", ");
    }
  }
  return out;
}

void student::addClass(string newClass)
{
  classes.push_back(newClass);
}
