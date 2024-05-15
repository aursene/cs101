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
  cout << "I am a new traveller! What is my name? ";
  cin >> name;

  rollStats();
  allocateStats();
  selectClass();
  calculateStats();
  hp = maxHp;
  // selectEquip();
}
character::~character()
{
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

void character::rollStats()
{
  for (int i = 0; i < 6; i++)
  {
    statSpread.push_back(rollOneStat());
  }
  sort(statSpread.begin(), statSpread.end(), greater<>());

  cout << "\033c";
  cout << "Let's start by choosing your stats, the attributes that will affect how well you can do different things!\n"
       << "These stats are found by rolling four 6-sided dice, then removing the lowest one and adding them all up\n\n";

  cout << "Your stat choices are: ";

  int counter{0};
  for (int k : statSpread)
  {
    counter++;
    cout << k << (counter == statSpread.size() ? " " : ", ");
  }
  cout << endl;

  cout << "Press the enter key to continue";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cin.get();
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
    cout << "\033c"
         << "Next, we'll choose what attribute to put those stats in. The bigger the number, the better you will do at "
            "tasks requiring that attribute\n";

    cout << "Select what stat you would like to allocate your " << statSpread[l] << " to." << endl;

    for (string h : statList)
    {
      j++;
      if (allocated[j - 1] == true)
        continue;
      cout << j << " - " << h << " = " << stats[j - 1] << endl;
    }

    bool breakout{false};
    while (breakout == false)
    {
      cin >> choice;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(10000000, '\n');
        cout << "Please enter the number next to the stat you would like to allocate to\n";
      }
      else if (choice > 6 || choice < 1)
      {
        cout << "Please enter the number next to the stat you would like to allocate to\n";
      }
      else if (allocated[choice - 1] == true)
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
  cout << "\033c"
       << "Your stats are: ";
  int tmp{};
  for (int j : stats)
  {
    cout << statList[tmp] << " - " << j << " (" << ((modifiers[tmp] < 1) ? "" : "+") << modifiers[tmp] << ")" << endl;
    tmp++;
  }
  cout << "\nPress enter to continue\n";
  cin.get();
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
  int classSelect;
  cout << "Now we'll select out starting class. This will slightly affect two of our stats, but is mostly used to "
          "determine what stat to use when attacking.\n"
       << "Please select your Class (Enter 1, 2, or 3): \n"
       << "(1) Rogue - High Dex, Low Con\n"
       << "(2) Fighter - High Str, Low Int\n"
       << "(3) Wizard - High Int, Low Str\n";
  cin >> classSelect;
  while (true)
  {
    if (classSelect == 1)
    {
      chClass = "Rogue";
      stats[1] += 2;
      stats[2] -= 2;
      break;
    }
    else if (classSelect == 2)
    {
      chClass = "Fighter";
      stats[0] += 2;
      stats[4] -= 2;
      break;
    }
    else if (classSelect == 3)
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


void character::selectEquip()
{
  int choice{};
  cout << "Please select your starting equipment (1-3): \n"
       << "(1) Ring of Accuracy\n"
       << "(2) Band of Health\n"
       << "(3) Shield\n";
  while (true)
  {
    cin >> choice;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(10000000, '\n');
    }
    else if (choice > 3 || choice < 1)
    {
      cout << "Please enter a number 1-3\n";
    }
    else if (choice == 1)
    {
      equipment.push_back("Ring of Accuracy");
      break;
    }
    else if (choice == 2)
    {
      equipment.push_back("Band of Health");
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
  for (string l : equipment)
  {
    if (l == "Headband of Intellect")
      modifiers[3] += 2;
    if (l == "Gloves of Hill Giant Strength")
      modifiers[0] += 2;
    if (l == "Boots of Speed")
      modifiers[1] += 2;
  }

  // ac calculations
  ac = 10 + modifiers[1];
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

  // toHit calculations
  toHit = 0;
  if (chClass == "Fighter")
  {
    toHit += modifiers[0];
  }
  else if (chClass == "Rogue")
  {
    toHit += modifiers[1];
  }
  else if (chClass == "Wizard")
  {
    toHit += modifiers[3];
  }
  else
  {
    cout << "\nInvalid class, is it still set as a commoner?\n";
  }

  if (find(equipment.begin(), equipment.end(), "Ring of Accuracy") != equipment.end())
  {
    toHit += 2;
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

int character::rollToHit()
{
  int result;
  result = d20(engine) + toHit;
  return result;
}

void character::getToHit()
{
  cout << "\n toHit = " << toHit << endl;
}

void character::takeDamage(int amount)
{
  hp -= amount;
}

void character::finalStats()
{
  cout << "Your name is " << name << "\nYou are a " << chClass << endl;

  cout << "\nYour stats are: ";
  int tmpTwo{};
  for (int j : stats)
  {
    cout << statList[tmpTwo] << " - " << j << " (" << ((modifiers[tmpTwo] < 1) ? "" : "+") << modifiers[tmpTwo] << ")"
         << endl;
    tmpTwo++;
  }

  cout << "\nYou have these in your inventory: " << endl << getEquipment() << endl;

  cout << "\nYour Max HP is: " << maxHp << "\nYour Current HP is: " << hp << endl;
}
