#include "character.h"
#include <iostream>
using namespace std;

player::player(string build)
{
  if (build == "Rogue")
  {
    health = 50;
    str = 3;
    dex = 5;
  }
  else if (build == "Ranger")
  {
    str = 3;
    dex = 3;
  }
  else if (build == "Fighter")
  {
    health = 150;
    str = 5;
    dex = 2;
  }
  else
  {
    cout << "\nInvalid\n";
  }
}

/* void player::move()
{
  char direction{'n'};
  int amount{1};
  cout << "Please select where you would like to move.\n(n, s, e, or w; amount you would like to move)";
  cin >> direction >> amount;
  switch (direction)
  {
  case 'n':
  case 'u':
    yPos += amount;
    break;
  case 's':
  case 'd':
    yPos -= amount;
    break;
  case 'e':
  case 'r':
    xPos += amount;
    break;
  case 'w':
  case 'l':
    xPos -= amount;
    break;
  default:
    cout << "\nerror\n";
    break;
  }
}

void player::checkPos()
{
  cout << "\nx Position: " << xPos << endl;
  cout << "y Position: " << yPos << endl << endl;
}*/

void player::checkStats()
{
  cout << endl;

  cout << health << endl;
  cout << str << endl;
  cout << dex << endl;
}
