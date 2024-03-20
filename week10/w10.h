#pragma once // i'm using this because I am am using a low-tech editor, and i'm not sure whether it protects against
             // loading this file multiple times (which is apparently bad)
#include <string>

class person // this is our class, it acts as a customizable type and any object created with it will have each of it's
             // attributes
{
public: // public here indicates that and of the following information will be accesible and viewable when called
        // outside of this class
  int xPos{2};
  int yPos{5};

  person(); // these are our "methods" (functions in duisgise). They are exclusive to their class, and are only defined
            // here. This one in particular is the constructor function, something that will run everytime a new member
            // of the class is created
  person(person &obj);
  person(person &&obj);
  void display();
  std::string getPrivateInfo();
  void witnessProtection();

private: // using private indicates that this information will only be usable and viewable inside of this class, it
         // cannot be called outside of it
  std::string ssn{"560 - 42 - 7501"}; // this is not my social security number
  std::string city{"chicago"};
};
