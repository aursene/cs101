#include "student.h"
#include <iostream>

using namespace std;

bool run{true};
int menu();

int main()
{
  cout << "Hello User!\n";
  student stu1;

  cout << "Welcome, " << stu1.getName() << ".";
  do
  {
    switch (menu())
    {
    case 1: {
      string classIn;
      cout << "\nWhat new classes are you taking? ";
      cin >> classIn;
      stu1.addClass(classIn);
    }
    break;

    case 2: {
      double gpaIn;
      cout << "\nWhat is your new GPA? ";
      cin >> gpaIn;
      stu1.setGpa(gpaIn);
    }
    break;

    case 3: {
      cout << "\nYour GPA is " << stu1.getGpa() << endl;
      cout << ((stu1.approval(stu1.getGpa()) == true) ? "Your GPA is higher than 3.0. Great job!"
                                                      : "Your GPA is lower than 3.0, lock in!");
    }
    break;

    case 4: {
      stu1.display();
    }
    break;

    case 9: {
      run = false;
    }
    break;

    default: {
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(100000, '\n');
      }
      cout << "\n**This should not happen, is there an error in selection?**\n";
    }
    break;
    }
  } while (run == true);

  cout << endl;
  return 0;
}

int menu()
{
  int selection;
  cout << "\nPlease select a menu option: "
       << "\n1 - Add a new class"
       << "\n2 - Update GPA"
       << "\n3 - Check GPA status"
       << "\n4 - Display all variables"
       << "\n9 - End program\n";
  cin >> selection;
  return selection;
}
