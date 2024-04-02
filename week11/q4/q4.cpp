#include "character.h"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <random>
#include <unistd.h>
using namespace std;

std::default_random_engine rng{static_cast<unsigned int>(time(0))};
std::uniform_int_distribution<unsigned int> getEncounter(1, 5);

vector<string> lootList{"Band of Health", "Ring of Accuracy", "Headband of Intellect", "Gloves of Hill Giant Strength",
                        "Boots of Speed"};

void encounters(character, int);

int main()
{
  cout << "Welcome to my game! Please press any key to start!";
  character Player1;
  // Player1.rollStats();
  // Player1.allocateStats();
  Player1.selectClass();
  // Player1.displayStats();
  Player1.selectEquip();
  cout << "You have a " << Player1.getEquipment() << ".";
  Player1.calculateStats();
  Player1.getToHit();
  Player1.displayStats();
  for (int k = 0; k < 5; k++)
  {
    encounters(Player1, getEncounter(rng));
    cout << Player1.getEquipment() << endl;
  }

  cout << "\n\ngod save the queen\n\n";
}

void encounters(character Player, int encounter)
{
  std::uniform_int_distribution<unsigned int> loot(0, lootList.size());
  char input;

  switch (encounter)
  {
  case 1:
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

        cout << "\nYou succesfully pry the item out from under the boulder. It was a " << lootList[lootGot] << ".\n";
        Player.equipment.push_back(lootList[lootGot]);
        lootList.erase(lootList.begin() + lootGot);
      }
      else
      {
        cout << "\nFailed to lift the boulder :(\n";
      }
      break;
    }
    else
    {
      break;
    }

  case 2:
    cout << "You come across a sphinx that asks you to answer a riddle, do you attempt to answer? (Y/n)";
    cin >> input;
    if (tolower(input) == 'y')
    {
      int roll{Player.rollCheck(Player.modifiers[3])};
      if (roll > 12)
      {
        int lootGot = loot(rng);

        cout << "\nYou succesfully answered the riddle! The sphinx rewards you with a " << lootList[lootGot] << ".\n";
        Player.equipment.push_back(lootList[lootGot]);
        // Player.addEquip(lootList[lootGot]);
        lootList.erase(lootList.begin() + lootGot);
      }
      else
      {
        cout << "\nYou failed to answer the riddle correctly. The Sphinx bids you to leave.\n";
      }
    }
    else
    {
      cout << "You walk past the sphinx, ignoring it completely.\n";
    }
    break;

  case 3:
    cout << "As you are walking the forest path you notice a small creature with a shiny object in it's mouth. As soon "
            "as it notices you, it starts to run away. Would you like to chase it? (Y/n)";
    cin >> input;
    if (tolower(input) == 'y')
    {
      int roll{Player.rollCheck(Player.modifiers[1])};
      if (roll > 12)
      {
        int lootGot = loot(rng);

        cout
            << "\nYou caught the critter! It drops the item it was carrying and you let it scurry away. The item was a "
            << lootList[lootGot] << ".\n";
        Player.equipment.push_back(lootList[lootGot]);
        // Player.addEquip(lootList[lootGot]);
        lootList.erase(lootList.begin() + lootGot);
      }
      else
      {
        cout << "\nThe critter succesfully escapes into the forest. Better luck next time!\n";
      }
    }
    else
    {
      cout << "You let the critter scurry away, in no hurry to chase after it.\n";
    }
    break;

  case 4:
    cout << "Travelling through the marshes you come across an old hag. She attempts to get you to make a deal for "
            "your firstborn child. Would you like to try and talk your way out of it? (Y/n)";
    cin >> input;
    if (tolower(input) == 'y')
    {
      int roll{Player.rollCheck(Player.modifiers[5])};
      if (roll > 12)
      {
        int lootGot = loot(rng);

        cout << "\nYou sweet talked her out of taking your firstborn, and talked her into giving you an item! It is a "
             << lootList[lootGot] << ".\n";
        Player.equipment.push_back(lootList[lootGot]);
        // Player.addEquip(lootList[lootGot]);
        lootList.erase(lootList.begin() + lootGot);
      }
      else
      {
        cout << "\nHer charms were too much for you, and now your firstborn is doomed the fate this hag chooses.\n";
      }
    }
    else
    {
      cout << "You run out of the marsh as fast as you can, barely escaping the hag's domain in time.\n";
    }
    break;

  case 5:
    cout << "You come across a bushel of fruits. You can't tell if they are poisonous or edible at first glance. Would "
            "you like to take a closer look? (Y/n)";
    cin >> input;
    if (tolower(input) == 'y')
    {
      int roll{Player.rollCheck(Player.modifiers[4])};
      if (roll > 12)
      {
        int lootGot = loot(rng);

        cout << "\nYou notice that they are winterberries, a highly poisonous fruit. But as you are taking a look, you "
                "notice a "
             << lootList[lootGot] << "in the bush!\n";
        Player.equipment.push_back(lootList[lootGot]);
        // Player.addEquip(lootList[lootGot]);
        lootList.erase(lootList.begin() + lootGot);
      }
      else
      {
        cout << "\nYou take a bite and immediately spit it out, these are winterberries! You take 1 point of damage.\n";
        Player.takeDamage(1);
      }
    }
    else
    {
      cout << "You decide to leave the bushel of berries alone.\n";
    }
    break;

  default:
    cout << "\nThis should not happen, is there an error in the rng?\n";
  }
}
