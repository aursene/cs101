#include <iostream>
#include <limits>
#include <vector>
using namespace std;

vector<char> t1{'A', 'B', 'C'};
vector<char> t2{};
vector<char> t3{};
bool win = false;
int source, dest;

void display();
void selection();
void move();

int main()
{
  // A really tidy main, simply calls the three functions responsible for running the game, then displays the board and
  // win message when the boolean win flag is set to true
  while (win == false)
  {
    display();   // displays the board
    selection(); // allows the player to select source and destination towers
    move();      // controls the movement of the letters between the towers
  }
  display();
  cout << "Congratulations! You beat the Tower of Hanoi!" << endl;
}

void display()
{
  cout << "T1: ";
  for (char i : t1) // ranged based loops, used to cycle through and display the full vector
    cout << i << "    ";
  cout << endl;

  cout << "T2: ";
  for (char i : t2)
    cout << i << "    ";
  cout << endl;

  cout << "T3: ";
  for (char i : t3)
    cout << i << "    ";
  cout << endl;
}

void selection() // allows selection of source and detination towers
{
  bool valid = false;
  while (valid == false)
  {
    cout << "Please select source tower: ";
    cin >> source;

    while (source != 1 && source != 2 && source != 3 && cin.fail()) // traps user in loop until good input
    {
      while (cin.fail()) // protects against bad inputs
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      cout << "Input is invalid, please enter a valid source (1, 2, or 3): ";
      cin >> source;
    }
    if (source == 1 || source == 2 || source == 3) // breaks out of while loop when acceptable input is taken
    {
      valid = true;
    }
  }

  // same loop as above, used to protect against bad inputs from user
  valid = false;
  while (valid == false)
  {
    cout << "Please select destination tower: ";
    cin >> dest;

    while (dest != 1 && dest != 2 && dest != 3 && cin.fail())
    {
      while (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      cout << "Input is invalid, please enter a valid dest (1, 2, or 3): ";
      cin >> dest;
    }
    if (dest == 1 || dest == 2 || dest == 3)
    {
      valid = true;
    }
  }
  cout << endl << endl;
}

// a mess of a brute force function, I will try to mark most of the important parts. It essentially copies the letter we
// want to use, clears the spot it use to occupy in the previous vector, and sends it to the end of the next vector
void move()
{
  char tmp{};
  if (source == 1) // case for moving letters from the first tower
  {
    if (dest == 1) // really only here to protect against bad inputs, it will never affect the actual state of the game
    {
      if (t1.empty()) // protects against checking an empty vector
      {
        tmp = t1.back();
        t1.pop_back();
        t1.push_back(tmp);
      }
      else if (t1.back() < t1.back()) // ensures no letters are placed in non-alphabetical order
        cout << "**Invalid Move**" << endl;
      else // if everything is all good, moves the letter
      {
        tmp = t1.back();
        t1.pop_back();
        t1.push_back(tmp);
      }
    }
    if (dest == 2)
    {
      if (t2.empty())
      {
        tmp = t1.back();
        t1.pop_back();
        t2.push_back(tmp);
      }
      else if (t1.back() < t2.back())
        cout << "**Invalid Move**" << endl;
      else
      {
        tmp = t1.back();
        t1.pop_back();
        t2.push_back(tmp);
      }
    }
    if (dest == 3)
    {
      if (t3.empty())
      {
        tmp = t1.back();
        t1.pop_back();
        t3.push_back(tmp);
      }
      else if (t1.back() < t3.back())
        cout << "**Invalid Move**" << endl;
      else
      {
        tmp = t1.back();
        t1.pop_back();
        t3.push_back(tmp);
      }
    }
  }
  if (source == 2)
  {
    if (dest == 1)
    {
      if (t1.empty())
      {
        tmp = t2.back();
        t2.pop_back();
        t1.push_back(tmp);
      }
      else if (t2.back() < t1.back())
        cout << "**Invalid Move**" << endl;
      else
      {
        tmp = t2.back();
        t2.pop_back();
        t1.push_back(tmp);
      }
    }
    if (dest == 2)
    {
      if (t2.empty())
      {
        tmp = t2.back();
        t2.pop_back();
        t2.push_back(tmp);
      }
      else if (t2.back() < t2.back())
        cout << "**Invalid Move**" << endl;
      else
      {
        tmp = t2.back();
        t2.pop_back();
        t2.push_back(tmp);
      }
    }
    if (dest == 3)
    {
      if (t3.empty())
      {
        tmp = t2.back();
        t2.pop_back();
        t3.push_back(tmp);
      }
      else if (t2.back() < t3.back())
        cout << "**Invalid Move**" << endl;
      else
      {
        tmp = t2.back();
        t2.pop_back();
        t3.push_back(tmp);
      }
    }
  }
  if (source == 3)
  {
    if (dest == 1)
    {
      if (t1.empty())
      {
        tmp = t3.back();
        t3.pop_back();
        t1.push_back(tmp);
      }
      else if (t3.back() < t1.back())
        cout << "**Invalid Move**" << endl;
      else
      {
        tmp = t3.back();
        t3.pop_back();
        t1.push_back(tmp);
      }
    }
    if (dest == 2)
    {
      if (t3.empty())
      {
        tmp = t3.back();
        t3.pop_back();
        t2.push_back(tmp);
      }
      else if (t3.back() < t2.back())
        cout << "**Invalid Move**" << endl;
      else
      {
        tmp = t3.back();
        t3.pop_back();
        t2.push_back(tmp);
      }
    }
    if (dest == 3)
    {
      if (t3.empty())
      {
        tmp = t3.back();
        t3.pop_back();
        t3.push_back(tmp);
      }
      else if (t3.back() < t3.back())
        cout << "**Invalid Move**" << endl;
      else
      {
        tmp = t3.back();
        t3.pop_back();
        t3.push_back(tmp);
      }
    }
  }
  if (t3.size() == 3) // updates win status if all letters are in the final tower
    win = true;
}
