#pragma once

#include <iostream>
#include <string>
using namespace std;

// base class - have crucial attributes/common attributes between 2 classes
class Artist
{
public:
  string Firstname;
  string Lastname;
  int Age;
  string Genre;

  Artist()
  {
  }
  // full constructor
  Artist(string fname, string lname, int cAge, string cGenre)
  {
    Firstname = fname;
    Lastname = lname;
    Age = cAge;
    Genre = cGenre;
  }

  void display()
  {
    cout << "\nFirst name: " << Firstname;
    cout << "\nlast name: " << Lastname;
    cout << "\nage: " << Age;
    cout << "\nGenre: " << Genre;
  }
};
