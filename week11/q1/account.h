#pragma once
#include <string>

class account
{
public:
  account();
  void deposit(double);
  void withdraw(double);
  double getBal();
  void setBal(double);
  std::string getName();
  int getID();
  void displayInfo();

private:
  std::string name{"Braxton Beckman"};
  int ID{682399};
  double bal{150.00};
};
