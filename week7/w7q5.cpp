/*
Braxton Beckman Week 7
Question 5: Random #'s
Objective: Using the default_random_engine and #include <random>
show exmaples of rolling a 6-sided, 10-sided, 12-sided die 10 times.
*/

#include <ctime>
#include <iostream>
#include <random>
#include <unistd.h>
using namespace std;

void rollD6();
void rollD12();
void rollD20();

// uses the default_random_engine and the current time since the epoch to allow functions to generate random numbers
default_random_engine engine{static_cast<unsigned int>(time(0))};

int main()
{
  cout << "\nRolling 10d6" << endl;
  rollD6();

  cout << "\nRolling 10d12" << endl;
  rollD12();

  cout << "\nRolling 10d20" << endl;
  rollD20();

  return 0;
}

// uses the value provided by the default random engine to roll a d6 10 times
void rollD6()
{
  uniform_int_distribution<unsigned int> roll(1, 6);

  for (int i = 0; i < 10; i++)
  {
    int result = roll(engine);
    cout << result << endl;
    usleep(300000);
    if (i == 9)
    {
      cout << "\n";
    }
  }
}

// uses the value provided by the default random engine to roll a d12 10 times
void rollD12()
{
  uniform_int_distribution<unsigned int> roll(1, 12);

  for (int i = 0; i < 10; i++)
  {
    int result = roll(engine);
    cout << result << endl;
    usleep(300000);
    if (i == 9)
    {
      cout << "\n";
    }
  }
}

// uses the value provided by the default random engine to roll a d20 10 times
void rollD20()
{
  uniform_int_distribution<unsigned int> roll(1, 20);

  for (int i = 0; i < 10; i++)
  {
    int result = roll(engine);
    cout << result << endl;
    usleep(300000);
    if (i == 9)
    {
      cout << "\n";
    }
  }
}
