#include "character.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;

std::default_random_engine engine{static_cast<unsigned int>(time(0))};
std::uniform_int_distribution<unsigned int> d6(1, 6);
std::uniform_int_distribution<unsigned int> d20(1, 20);
vector<string> statList{"Strength", "Dexterity", "Constitution", "Wisdom", "Intelligence", "Charisma"};

character::character()
{
  cout << "I am born!\n";
}

int character::rollCheck(int mod)
{
  int roll{}, result{};
  roll = d20(engine);
  result = roll + mod;
  return result;
}

string character::getClass()
{
  return chClass;
}

void character::selectClass()
{
  string classSelect;
  cout << "Please select your Class: \n"
       << "Rogue - High Dex, Low Con\n"
       << "Fighter - High Str, Low Int\n"
       << "Wizard - High Int, Low Str\n";
  cin >> classSelect;
  while (true)
  {
    if (classSelect == "Rogue")
    {
      chClass = "Rogue";
      stats[1] += 2;
      stats[2] -= 2;
      break;
    }
    else if (classSelect == "Fighter")
    {
      chClass = "Fighter";
      stats[0] += 2;
      stats[4] -= 2;
      break;
    }
    else if (classSelect == "Wizard")
    {
      chClass = "Wizard";
      stats[4] += 2;
      stats[0] -= 2;
      break;
    }
    else
    {
      cout << "Please select one of the three available classes";
    }
  }
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
  vector<string>::iterator it;

  for (int l = 0; l < statSpread.size(); l++)
  {
    int choice;
    int j{};
    // system("clear");
    cout << "\033c";

    cout << "Select what stat you would like to allocate your " << statSpread[l] << " to." << endl;

    for (string h : statList)
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
  // system("clear");
  cout << "\033c";
}

void character::displayStats()
{
  cout << "Your stats are: ";
  int tmp{};
  for (int j : stats)
  {
    cout << statList[tmp] << " - " << j << " (" << ((modifiers[tmp] < 1) ? "" : "+") << modifiers[tmp] << ")" << endl;
    tmp++;
  }
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

void character::selectEquip()
{
  int choice{};
  cout << "Please select your starting equipment: \n"
       << "1 - Ring of Accuracy\n"
       << "2 - Band of Health\n"
       << "3 - Shield\n";
  while (true)
  {
    cin >> choice;
    if (choice == 1)
    {
      equipment.push_back("ringAccuracy");
      break;
    }
    else if (choice == 2)
    {
      equipment.push_back("ringHealth");
      break;
    }
    else if (choice == 3)
    {
      equipment.push_back("shield");
      break;
    }
    else
    {
      cout << "Invalid choice\n";
    }
  }
}

void character::addEquip(string loot)
{
  equipment.push_back(loot);
  for (string i : equipment)
  {
    cout << endl << "**" << i << "**" << endl;
  }
}

string character::getEquipment()
{
  string output;
  for (int j = 0; j < equipment.size(); j++)
  {
    output = output + equipment[j] + ", ";
  }
  return output;
}

void character::calculateStats()
{
  // modifier calculations
  int counter{};
  for (int j : stats)
  {
    modifiers[counter] = ((j - 10) / 2);
    counter++;
  }
  // ac calculations
  ac = 10 + dex;
  for (string i : equipment)
  {
    if (i == "Leather Armor")
      ac = 11 + modifiers[1];
  }

  // hp calculations
  if (chClass == "Fighter")
  {
    maxHp = 10 + modifiers[2];
  }
  else if (chClass == "Rogue")
  {
    maxHp = 8 + modifiers[2];
  }
  else if (chClass == "Wizard")
  {
    maxHp = 6 + modifiers[2];
  }
  else
  {
    cout << "\nInvalid class, is it still set as commoner?\n";
  }
}

string character::getModifiers()
{
  int j{};
  string output;

  for (int i : modifiers)
  {
    output += to_string(i);
    if (modifiers.size() - 1 != j)
    {
      output += ", ";
    }
    else
    {
      output += ".";
    }
    j++;
  }

  return output;
}
