#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
  // This is a class, effectively a container that allows us to organize information and then manipulate it, either
  // inside of or outside of the class. We can then use these classes to create objects, allowing those objects to
  // inherit the properties of the class
  class person
  {
  public: // public here indicates that and of the following information will be accesible and viewable when called
          // outside of this class
    int xPos{2};
    int yPos{5};

  private: // using private indicates that this information will only be usable and viewable inside of this class, it
           // cannot be called outside of it
    int ssn{560 - 42 - 7501};
  };

  person Mary; // this creates an object, in this case Mary, and gives it all of the properties of the preceding class,
               // in this case "person"

  cout << "Mary's x position is: " << Mary.xPos << endl << "Mary's y position is: " << Mary.yPos << endl << endl;

  cout << "Mary is moving";
  for (int i = 0; i < 4; i++)
  {
    cout << ".";
    usleep(1000000);
    fflush(stdout);
  }
  cout << endl << endl;

  Mary.xPos = 8; // We use a period here to indicate that we want to access information inside of this object
  Mary.yPos = 6;

  cout << "Mary's x position is now: " << Mary.xPos << endl << "Mary's y position is now: " << Mary.yPos << endl;
}

// Explanation of Public vs Private space:
// https://www.geeksforgeeks.org/difference-between-public-and-private-in-c-with-example/
//
// Explanation of Private vs Protected space:
// https://stackoverflow.com/questions/224966/what-is-the-difference-between-private-and-protected-members-of-c-classes
