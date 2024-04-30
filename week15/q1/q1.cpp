#include "q1.h"
#include <iostream>
using namespace std;

int main()
{
  person Braxton(20, "Braxton", "9:00");
  cout << "Braxton's attributes are:";
  Braxton.display();

  Braxton.age = 21;
  Braxton.startTime = "10:00";

  cout << "\n\nBraxton's attributes are now: ";
  Braxton.display();
}
