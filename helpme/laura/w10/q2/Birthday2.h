#pragma once
#include <iostream>
#include <string>
using namespace std;

// class helps defined what we need/ send copies
#pragma once
class Birthday2
{
  // delaring a space as public will allow anyone to modify
public:
  // these are our attributes: variables used by .h program
  int _month = 2;
  int _day = 3;
  int _year = 1;
  // created a string attribute
  string _wish{"apon a candle"};

  void display() // this is our method - a fucntion in class will allow access to pub & private class
  {
    cout << "\nthe data is month = " << _month;
    cout << "\nthe data is day = " << _day;
    cout << "\nthe data is year = " << _year;
    cout << "\nthe wish = " << _wish;
  }
};
