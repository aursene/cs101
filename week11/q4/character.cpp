#include "character.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <unistd.h>
#include <vector>
using namespace std;

std::default_random_engine engine{static_cast<unsigned int>(time(0))};
std::uniform_int_distribution<unsigned int> d6(1, 6);

character::character()
{
  cout << "\nI am born!\n";
}

int character::rollOneStat()
{
  std::vector<int> statRolls{};

  for (int i = 0; i < 4; i++)
  {
    statRolls.push_back(d6(engine));
  }

  cout << endl;
  sort(statRolls.begin(), statRolls.end(), greater<>());
  statRolls.pop_back();

  int k{0};
  int total{0};
  for (int l : statRolls)
  {
    total += statRolls[k];
    k++;
  }
  return total;
}

void character::allocateStats()
{
  int j{};
  vector<bool> allocated{false, false, false, false, false, false};
  vector<string> statAllocation{"Strength", "Dexterity", "Constitution", "Wisdom", "Intelligence", "Charisma"};
  vector<string>::iterator it;

  for (int l = 0; l < statSpread.size(); l++)
  {
    int choice;
    int j{};
    cout << "Select what stat you would like to allocate your " << statSpread[l] << " to." << endl;

    for (string h : statAllocation)
    {
      j++;
      cout << j << " - " << h << " = " << stats[j - 1] << endl;
    }

    bool breakout{false};
    while (breakout == false)
    {
      cin >> choice;
      if (allocated[choice - 1] == true)
      {
        cout << "Stat has already been allocated: ";
      }
      else
      {
        breakout = true;
        stats[choice - 1] = statSpread[l];
        cout << endl;
        allocated[choice - 1] = true;
      }
    }
  }
  for (int j : stats)
    cout << j << ((j == stats.back()) ? " " : ", ");
  system("clear");
}

void character::rollStats()
{
  cout << endl << "Your stat spread is: ";
  for (int i = 0; i < 6; i++)
  {
    statSpread.push_back(rollOneStat());
  }
  sort(statSpread.begin(), statSpread.end(), greater<>());
  int counter{0};
  for (int k : statSpread)
  {
    counter++;
    cout << k << (counter == statSpread.size() ? " " : ", ");
  }
  cout << endl;
}
