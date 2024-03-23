#include "character.h"
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
  character Player1;
  Player1.rollStats();
  Player1.allocateStats();
  Player1.displayStats();
  // Player1.selectClass();
  // Player1.displayStats();
  // Player1.selectEquip();
  // cout << "You have a " << Player1.getEquipment() << ".";
  Player1.calculateStats();
  cout << "\nFinal Mods Echo\n";
  int j{};
  for (int i : Player1.modifiers)
  {
    cout << i;
    if (Player1.modifiers.size() - 1 != j)
    {
      cout << ", ";
    }
    else
    {
      cout << "." << endl;
    }
    j++;
  }

  cout << "\n\ngod save the queen\n\n";
}
