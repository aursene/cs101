#include "character.h"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <random>
#include <unistd.h>
using namespace std;

std::default_random_engine rng{static_cast<unsigned int>(time(0))};
std::uniform_int_distribution<unsigned int> getEncounter(1, 5);

vector<string> lootList{"Band of Health",
                        "Ring of Accuracy",
                        "Headband of Intellect",
                        "Gloves of Hill Giant Strength",
                        "Boots of Speed",
                        "Blade of Smiting",
                        "Crown of Karsus",
                        "Gauntlets of Smithing",
                        "Ring of Wild Magic",
                        "Doran's Blade",
                        "Yew Bow",
                        "Leather Armor"};

void encounters(character &, int);
char getYn();
int menu();
void menuSelect(character &);

int main()
{
  cout << "\033[2J\033[1;1H";
  cout << "Welcome to my game! Please press the enter key to start!";
  cin.get();
  character Player1;
  // Player1.calculateStats();
  while (true)
  {
    if (Player1.encountersSeen > 4)
    {
      cout << "\033c"
           << "Your journey is over! Here are your final attributes: " << endl;
      Player1.finalStats();
      cout << "\nPress enter key to continue";
      cin.get();
      break;
    }
    menuSelect(Player1);
    Player1.calculateStats();
  }

  cout << "\033c"
       << "Now we are going to try this again, but with a new character";
  cout << "\n\nPress enter key to continue";
  cin.get();


  character Player2;
  Player2.calculateStats();
  while (true)
  {
    if (Player2.encountersSeen > 4)
    {
      cout << "\033c"
           << "Your journey is over! Here are your final attributes: " << endl;
      Player2.finalStats();
      break;
    }
    menuSelect(Player2);
    Player2.calculateStats();
  }

  cout << "\033c"
       << "Thanks for playing! That's all there is to the game, but I will display both stats so you can see the "
          "differences!\n";

  cout << "***Player 1***\n";
  Player1.finalStats();

  cout << "***Player 2***\n";
  Player2.finalStats();
}


// used as a display and input for the below function
int menu()
{
  int input;
  cout << "\033[2J\033[1;1H";
  cout << "Now the game begins! From here you can start entering \"ecounters\", check your stats, or check equipment "
          "(gained from encounters). After going through 5 encounters the journey will be over, and your character's "
          "final stats and equipment will be displayed!\n"
       << "What would you like to do?"
       << "\n(1) Continue on your journey"
       << "\n(2) Check your equipment"
       << "\n(3) Check your stats\n";

  while (true)
  {
    cin >> input;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(1000000, '\n');
    }
    else if (input < 1 || input > 4)
    {
      cout << "Please enter a valid menu option";
    }
    else
    {
      return input;
    }
  }
}


// using the above menu function as a display and input, this function will allow you to interact with the primary menu
// of the game
void menuSelect(character &Player)
{
  for (int k = 0; k < 5; k++)
  {
    switch (menu())
    {
    case 1:
      encounters(Player, getEncounter(rng));
      break;

    case 2:
      cout << "\033c"
           << "Your equipment is " << Player.getEquipment() << endl
           << "Press enter key to continue";
      cin.get();
      break;

    case 3:
      Player.displayStats();
      break;

    case 4:
      break;
    }

    cout << "\nPress enter to continue";
    cin.get();
  }
}


// a simple function used to protect various inputs
char getYn()
{
  char input;

  while (true)
  {
    cin >> input;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(100000000, '\n');
      cout << "Please enter Y/n";
    }
    else if (tolower(input) != 'y' && tolower(input) != 'n')
    {
      cout << "Please enter Y/n ";
    }
    else
    {
      return input;
    }
  }
}


// This is a very large switch, designed to take in a randomly generated value and a character object and run that
// character through an encounter according to the random number. Depending on the outcome of the encounter, it will add
// a random equipment from the list of equipment to the object's equipment list
void encounters(character &Player, int encounter)
{
  std::uniform_int_distribution<unsigned int> loot(0, lootList.size() - 1);
  char input;


  cout << "\033[2J\033[1;1H";
  Player.displayStats();
  cout << endl;


  switch (encounter)
  {
  case 1:
    cout << "You've come across a large boulder in your travels, and it looks like there might be something under it. "
            "Would you like to try lifting it? (Y/n)";
    input = getYn();
    if (input == 'y' || input == 'Y')
    {
      int roll{Player.rollCheck(Player.modifiers[0])};
      cout << endl << "Rolling 1d20 + " << Player.modifiers[0] << endl << roll << endl;
      if (roll > 12)
      {
        int lootGot = loot(rng);

        cout << "\nYou succesfully pry the item out from under the boulder. It was a " << lootList[lootGot] << ".\n";
        // Player.equipment.push_back(lootList[2]);
        Player.addEquip(lootList[lootGot]);
        lootList.erase(lootList.begin() + lootGot);
      }
      else
      {
        cout << "\nYou failed to lift the boulder, leaving the item for another traveller.\n";
      }
      break;
    }
    else
    {
      cout << "You walk past the boulder, leaving the item for another traveller.";
      break;
    }

  case 2:
    cout << "You come across a sphinx that asks you to answer a riddle, do you attempt to answer? (Y/n)";
    input = getYn();
    if (tolower(input) == 'y')
    {
      // cout << "Rolling 1d20 + " << Player.modifiers[3];
      int roll{Player.rollCheck(Player.modifiers[3])};
      cout << endl << "Rolling 1d20 + " << Player.modifiers[3] << endl << roll << endl;
      if (roll > 12)
      {
        int lootGot = loot(rng);

        cout << "\nYou succesfully answered the riddle! The sphinx rewards you with a " << lootList[lootGot] << ".\n";
        // Player.equipment.push_back(lootList[lootGot]);
        Player.addEquip(lootList[lootGot]);
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
    input = getYn();
    if (tolower(input) == 'y')
    {
      // cout << "Rolling 1d20 + " << Player.modifiers[1];
      int roll{Player.rollCheck(Player.modifiers[1])};
      cout << endl << "Rolling 1d20 + " << Player.modifiers[1] << endl << roll << endl;
      if (roll > 12)
      {
        int lootGot = loot(rng);

        cout
            << "\nYou caught the critter! It drops the item it was carrying and you let it scurry away. The item was a "
            << lootList[lootGot] << ".\n";
        // Player.equipment.push_back(lootList[lootGot]);
        Player.addEquip(lootList[lootGot]);
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
    input = getYn();
    if (tolower(input) == 'y')
    {
      // cout << "Rolling 1d20 + " << Player.modifiers[5];
      int roll{Player.rollCheck(Player.modifiers[5])};
      cout << endl << "Rolling 1d20 + " << Player.modifiers[5] << endl << roll << endl;
      if (roll > 12)
      {
        int lootGot = loot(rng);

        cout << "\nYou sweet talked her out of taking your firstborn, and talked her into giving you an item! It is a "
             << lootList[lootGot] << ".\n";
        // Player.equipment.push_back(lootList[lootGot]);
        Player.addEquip(lootList[lootGot]);
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

    input = getYn();
    if (tolower(input) == 'y')
    {
      // cout << "Rolling 1d20 + " << Player.modifiers[4];
      int roll{Player.rollCheck(Player.modifiers[4])};
      cout << endl << "Rolling 1d20 + " << Player.modifiers[4] << endl << roll << endl;
      if (roll > 12)
      {
        int lootGot = loot(rng);

        cout << "\nYou notice that they are winterberries, a highly poisonous fruit. But as you are taking a look, you "
                "notice a "
             << lootList[lootGot] << "in the bush!\n";
        // Player.equipment.push_back(lootList[lootGot]);
        Player.addEquip(lootList[lootGot]);
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
  Player.encountersSeen += 1;
  cin.get();
}
