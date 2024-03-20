#include <iostream>
#include <vector>
using namespace std;

vector<char> t1{'A', 'B', 'C', 'D'};
vector<char> t2{};
vector<char> t3{};
bool win = false;
int source, dest;

void display();
void selection();
void move();

int main()
{
  while (win == false)
  {
    display();
    selection();
    move();
  }
  display();
  cout << "Congratulations! You beat the Tower of Hanoi!" << endl;
}

void display()
{
  cout << "T1: ";
  for (char i : t1)
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

void selection()
{
  bool valid = false;
  while (valid == false)
  {
    cout << "Please select source tower: ";
    cin >> source;

    while (source != 1 && source != 2 && source != 3 || cin.fail())
    {
      while (cin.fail())
      {
        cin.clear();
        cin.ignore();
      }
      cout << "Input is invalid, please enter a valid source (1, 2, or 3)" << endl;
      cin >> source;
    }
    if (source == 1 || source == 2 || source == 3)
    {
      valid = true;
    }
  }

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
        cin.ignore();
      }
      cout << "Input is invalid, please enter a valid dest (1, 2, or 3)";
      cin >> dest;
    }
    if (dest == 1 || dest == 2 || dest == 3)
    {
      valid = true;
    }
  }
  cout << endl << endl;
}

void move()
{
  char tmp{};
  if (source == 1)
  {
    if (dest == 1)
    {
      if (t1.empty())
      {
        tmp = t1.back();
        t1.pop_back();
        t1.push_back(tmp);
      }
      else if (t1.back() < t1.back())
        cout << "**Invalid Move**" << endl;
      else
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
  if (t3.size() == 4)
    win = true;
}
