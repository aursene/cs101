#include "character.h"
#include <iomanip>
#include <iostream>
#include <random>
#include <unistd.h>
using namespace std;

std::default_random_engine rng{static_cast<unsigned int>(time(0))};

vector<string> lootList{"Ring of Health", "Ring of Accuracy"};

void encounters(character, int);

int main()
{
  cout << "Welcome to my game! Please press any key to start!";
  character Player1;
  Player1.rollStats();
  Player1.allocateStats();
  Player1.selectClass();
  // Player1.displayStats();
  Player1.selectEquip();
  cout << "You have a " << Player1.getEquipment() << ".";
  Player1.calculateStats();
  Player1.displayStats();
  for (int k = 0; k < 5; k++)
  {
    encounters(Player1, 1);
  }

  cout << "\n\ngod save the queen\n\n";
}

void encounters(character Player, int encounter)
{
  std::uniform_int_distribution<unsigned int> loot(0, lootList.size());

  switch (encounter)
  {
  case 1:
    char input;
    cout << "You've come across a large boulder in your travels, and it looks like there might be something under it. "
            "Would you like to try lifting it? (Y/n)";
    cin >> input;
    if (input == 'y' || input == 'Y')
    {
      int roll{Player.rollCheck(Player.modifiers[0])};
      cout << endl << roll << endl;
      if (roll > 12)
      {
        int lootGot = loot(rng);

        cout << "\nYou succesfully pry the item out from under the boulder. It was a " << lootList[lootGot];
        Player.addEquip(lootList.at(lootGot));
        lootList.erase(lootList.begin() + lootGot);
      }
      else
      {
        cout << "\nFailed to lift the boulder :(";
      }
      break;
    }
    else
    {
      break;
    }

  case 2:
    break;

  case 3:
    break;

  case 4:
    break;

  case 5:
    break;

  default:
    cout << "\nThis should not happen, is there an error in the rng?\n";
  }
}
