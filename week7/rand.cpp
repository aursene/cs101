#include <ctime>
#include <iostream>
#include <random>
#include <unistd.h>

using namespace std;

int die{6};

void rollDice();

int main()
{
  while (true)
  {
    cout << "What dice would you like to roll? (0 to stop) ";
    cin >> die;
    if (die == 0)
    {
      break;
    }
    else
    {
      cout << "\n\nRolling 10d" << die << endl;
      rollDice();
    }
  }

  return 0;
}

void rollDice()
{
  default_random_engine engine{static_cast<unsigned int>(time(0))};
  uniform_int_distribution<unsigned int> roll(1, die);

  for (int i = 0; i < 10; i++)
  {
    int result = roll(engine);
    cout << result << endl;
    usleep(500000);
    if (i == 9)
    {
      cout << "\n\n";
    }
  }
}
