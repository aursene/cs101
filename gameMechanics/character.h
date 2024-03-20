#include <iostream>
using namespace std;

class player
{
public:
  player(string build);
  void move();
  // void checkPos();
  void checkStats();

  int health{100};
  int str{1};
  int dex{1};
};
