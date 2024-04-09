/* Laura Reyes  3/19/2024

  W10 Q2 Methods

  purpose: using methods

*/

// interpret the .h file
#include "Birthday2.h"

#include <iostream>

using namespace std;

int main()
{
  cout << "\n\t\tMethods()\n\n";

  // use the name of the header file to create our objects
  Birthday2 my;
  // using a second object to link .h to .cpp
  Birthday2 your;

  cout << "\n\nDisplay default attributes: ";
  // display default attributes more secure by not allowing chnages
  my.display();

  my._day = 14;
  my._month = 1;
  my._year = 2003;
  // display the modified attributes
  my.display();

  cout << "\n\nDisplay the modified attributes: ";
  // display default attributes more secure by not allowing chnages
  your.display();

  your._day = 3;
  your._month = 28;
  your._year = 1979;
  your._wish = "upon a star ";

  return 0;
}
