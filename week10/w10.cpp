#include "w10.h" // loads all of the definitions from the associated header file
#include <iostream>
using namespace std;

person::person() // a special function, known as the constructor function, that automatically runs anytime we create
                 // (declare) a new object using this class
{
  cout << "Hello World! I'm a Person!\n";
}

person::person(person &obj)
{
  cout << "Hello World! I'm a Person made by copying another objects attributes!\n";
}

person::person(person &&obj)
{
  cout << "Hello World! I'm a person who stole someone's identity!\n";
}

void person::display() // really no different than any other function other than the fact that it is locked to objects
                       // from the person class, and it can use variable located inside the class
{
  cout << "xPos is " << xPos << ", yPos is " << yPos << endl;
}

string person::getPrivateInfo()
{
  string information = "\ntheir ssn is: " + ssn + "\nthey are currently in " + city + "\n";
  return information;
}

void person::witnessProtection()
{
  string social{"xxx-xx-xxxx"};
  string newCity{"cincinatti"};

  cout << "\nThis person needs to be relocated. Please give them a new ssn (" << social << "): ";
  cin >> social;
  cout << "\nWhere should we send them? (please one word cities i can't get getline to work)";
  cin >> newCity;

  ssn = social;
  city = newCity;
}
