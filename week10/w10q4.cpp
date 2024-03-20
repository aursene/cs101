#include "w10.h" // loads all of the functions we have defined here so we can use them
#include <iostream>
using namespace std;

int main()
{
  person Mary; // the declaration of an object from our brand spanking new class, "person". "Mary" now contains a
               // position in space (two integers), and the ability to call the constructor function (which it does on
               // creation) and the display function

  Mary.display(); // the afformentioned display function, it will display the two integers Mary has (which is currently
                  // a position on a plane)

  cout << Mary.getPrivateInfo();
  Mary.witnessProtection();
  cout << Mary.getPrivateInfo();

  cout << "\n---------------\n\n";

  person Jim(Mary);

  cout << "\n---------------\n\n";

  person Steve(std::move(Mary));
  cout << "\n---------------\n";

  return 0; // it felt too small without it
}
