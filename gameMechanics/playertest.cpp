#include "character.h"
#include <iostream>
using namespace std;

string build;

int main()
{
  // int startX{}, startY{};
  //  cout << "Where would you like to start? (x, y) ";
  //  cin >> startX >> startY;
  cout << "Please select your class: \n1: Rogue\n2: Ranger\n3: Fighter\n";
  player Player1(build);
  Player1.checkStats();

  cout << "\nMake a loop that traps player in battle sequence.\nfigure out how to check for accuracy when attacking\n "
          "prompt player to pick a magic item (Multiple)? that affects hit rolls/various stats, maybe new mechanics "
          "(look that one up)\n really overengineer this chit cause it's fun dn the only difficult assignment you've "
          "had all week\nkeep taking care of yourself, you really deserve it and are pretty fucking cool not to "
          "mention a PRODIGY PROGRAMMER if I do say so myself\nalso use the minecraft monofont more, that shit would "
          "go so hard\nand figure out how to integrate this into your daily life, cause that'd be pretty fun and "
          "pretty rad\nalright i'm gonna stop using this as a  hight journal, goodnight braxton from tomorrow i hope I "
          "charged this\n";
  /*bool done{false};
  while (done == false)
  {
    char cont{'y'};
    Player.checkPos();
    Player.move();
    Player.checkPos();
    cout << "\nKeep going? (Y/n) ";
    cin >> cont;
  }*/
}
