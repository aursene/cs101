#include "employee.h"
#include <iostream>
using namespace std;

int main()
{
  employee Larry;
  cout << "Your first name is " << Larry.getFirst();

  cout << "\nYour last name is ";
  Larry.getLast();

  cout << endl << endl;
  cout << Larry.toString() << endl;
}
