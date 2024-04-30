#pragma once
#include <iostream>
#include <string>
using namespace std;

class person
{
public:
  int age{};
  string name{};
  string startTime{};
  person();

  person(int nAge, string nName, string nstartTime)
  {
    age = nAge;
    name = nName;
    startTime = nstartTime;
  };

  void display()
  {
    cout << "\nAge = " << age << "\nName = " << name << "\nThey start at " << startTime << endl;
  }
};
