#include "account.h"
#include <iostream>
using namespace std;

account::account()
{
  /*cout << "What is your name? ";
  cin >> name;

  cout << "What is your ID number? ";
  cin >> ID;

  cout << "How much do you have in your bank account? ($x.xx) ";
  cin >> bal;*/

  cout << "Created!\n\n";
}

void account::deposit(double amount)
{
  bal += amount;
}

void account::withdraw(double amount)
{
  bal -= amount;
}

double account::getBal()
{
  return bal;
}

void account::setBal(double amount)
{
  bal = amount;
}

std::string account::getName()
{
  return name;
}

int account::getID()
{
  return ID;
}

void account::displayInfo()
{
  cout << endl << name << endl << ID << endl << "$" << bal << endl;
}
