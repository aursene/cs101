/*
Braxton Beckman Week 7
Question 4: Global and Local Counters
Objective: Show examples of global, local, and static counters by displaying either A, B, or C an amount of times equal
to the amount of times the function has run.
*/

#include <iostream>

using namespace std;

int counterA{};

void A();
void B();
void C(int);

int main()
{
  char input{};
  int counterC{0};

  while (input != 'Q')
  {
    cout << "Please enter A, B, or C (Q to stop the program): ";
    cin >> input;

    // uses a case-switch to run certain functions based on user input
    switch (input)
    {
    case 'A':
      A();
      break;

    case 'B':
      B();
      break;

    case 'C':
      counterC++; // counter used to run C() a given number of times
      for (int k = 0; k < counterC; k++)
      {
        C(counterC);
      }
      cout << "\n";
      break;

    case 'Q': // stops program
      cout << "Goodbye" << endl;
      break;

    default:
      cout << "Invalid input" << endl;
    }
  }
}

// all functions below here display
// a certain amount of letters based
// on how many times they've run

void A() // uses a global counter
{
  counterA++;
  for (int i = 0; i < counterA; i++)
  {
    cout << "A";
  }
  cout << "\n";
}

void B() // uses a local, static counter
{
  static int counterB;
  counterB++;

  for (int i = 0; i < counterB; i++)
  {
    cout << "B";
  }
  cout << "\n";
}

void C(int counter) // uses a counter located in main
{
  cout << "C";
}
