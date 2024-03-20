/*
Braxton Beckman Week 7
Question 2: Calll-By-Referece
Objective: Show examples of passing an integer into a function
  using call-by-value and call-by-reference
*/

#include <iostream>
using namespace std;

int x;
int y;

int xvalue(int);
int yreference(int &);

int main()
{
  cout << "Please enter a value for x, then y: ";
  cin >> x >> y;
  cout << "This is x*x using call-by-value: " << xvalue(x) << endl;
  cout << "This is y*y using call-by-reference: " << yreference(y) << endl;
}

// creates a copy of x and squares it, then returns the result to main()
int xvalue(int x)
{
  int xResult = x * x;
  return xResult;
}

// catches the address of int y, then squares it and replaces the original variable
int yreference(int &y)
{
  int yResult = y * y;
  return yResult;
}
