#include <iostream>
using namespace std;

string number;
bool palin{false};

int main()
{
  do
  {
    cout << "What number would you like to check? (enter a numeric palindrome to exit) ";
    cin >> number;

    for (int i = 0; i < number.length(); i++)
    {
      if (number[i] == number[number.length() - 1 - i])
      {
        palin = true;
        continue;
      }
      else
      {
        palin = false;
        break;
      }
    }
    if (palin == false)
      cout << number << " is not a palindrome :(" << endl;
    else
    {
      cout << endl << number << " is a palindrome, ";
      if (number.length() % 2 == 0)
      {
        cout << "The middle points are positions " << number.length() / 2 << " and " << (number.length() / 2) + 1
             << ", (" << number[number.length() / 2] << ", and " << number[number.length() / 2 - 1] << " respectively) "
             << endl;
      }
      else
      {
        cout << "The middle point is position " << number.length() / 2 + 1 << ", (" << number[number.length() / 2]
             << ")" << endl;
      }
    }
  } while (palin == false);
}
