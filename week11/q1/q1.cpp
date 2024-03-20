#include "account.h"
#include <iomanip>
#include <iostream>
using namespace std;

double depo{0.00};
double withd{0.00};
double set{0.00};
int choice{0};

bool breakout{false};

void displayChoice();

int main()
{
  account Braxton;
  while (breakout != true)
  {
    displayChoice();
    cout << "Please select your action: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Please enter how much you would like to deposit: ";
      cin >> depo;
      Braxton.deposit(depo);
      cout << "\nYour new balance is $" << fixed << setprecision(2) << Braxton.getBal() << endl << endl;
      break;

    case 2:
      cout << "Please enter how much you would like to withdraw: ";
      cin >> withd;
      Braxton.withdraw(withd);
      cout << "\nYour new balance is $" << fixed << setprecision(2) << Braxton.getBal() << endl << endl;
      break;

    case 3:
      cout << "Please enter what you would like to set your balance to: ";
      cin >> set;
      Braxton.setBal(set);
      cout << "\nYour new balance is $" << fixed << setprecision(2) << Braxton.getBal() << endl << endl;
      break;

    case 4:
      cout << "Your name is " << Braxton.getName() << endl << endl;
      break;

    case 5:
      cout << "Your ID is " << Braxton.getID() << endl << endl;
      break;

    case 9:
      breakout = true;
      break;

    default:
      cout << "That was not a choice." << endl << endl;
      break;
    }
  }
}

void displayChoice()
{
  cout << "1 - Deposit\n2 - Withdraw\n3 - Set Balance\n4 - View Name\n5 - View ID"
       << "\n9 - Quit" << endl;
}
