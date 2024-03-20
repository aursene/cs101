#pragma once
#include <string>
using namespace std;

class employee
{
private:
  string fname{"Braxton"};
  string lname{"Beckman"};
  string birthdate{};
  string address{};
  string city{};
  string state{};
  int zip{};
  int phone{};
  string email{};
  string hourlyrate{};

public:
  employee();
  string getFirst();
  void getLast();
  string toString();
};
