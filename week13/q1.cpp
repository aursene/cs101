#include <iostream>

using namespace std;


int main()
{
  int x{5};
  int *definitelyNotX = &x;

  char letter{'a'};
  char *definitelyNotALetter = &letter;


  cout << "This is x: " << x << endl;
  cout << "This is definitely not x: " << *definitelyNotX << endl;
  cout << "This is where x is located in memory: " << definitelyNotX << endl;

  *definitelyNotX = 10;
  cout << "This is new x: " << x << endl;
  cout << "This is new definitely not x: " << *definitelyNotX << endl;

  cout << "\n\n";
  cout << "This is a letter: " << letter << endl;
  cout << "This is definitely not that letter: " << *definitelyNotALetter << endl;
  cout << "This is where that letter is located in memory: " << definitelyNotALetter << endl;

  return 0;
}
