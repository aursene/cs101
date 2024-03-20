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
  Player1.selectClass();
  Player1.displayStats();
  cout << "\n\ngod save the queen\n\n";
}
