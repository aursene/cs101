/*
Braxton Beckman Week 7
Lab 5:  Sorting and Searching
Objective: Aks user for their name and sort it alhpabetically. Then use a binary
search to look for vowels and display how many cycles it took to find them.
*/
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

string name;
string sortedName;

int binarySearch(string, int, int, char, int);
void sortName(string &);

int main()
{
  cout << "Please enter your name: ";
  cin >> name;
  cout << "\n";
  sortName(name);
  for (int i = 0; i < name.length(); i++)
  {
    cout << name[i];
  }
  cout << "\n";
  {
    int counter = 0;
    char target{'a'};
    int l = 0;
    int r = name.length() - 1;
    binarySearch(name, l, r, target, counter);
  }
  {
    int counter = 0;
    char target = 'o';
    int l = 0;
    int r = name.length() - 1;
    binarySearch(name, l, r, target, counter);
  }
  {
    int counter = 0;
    char target = 'u';
    int l = 0;
    int r = name.length() - 1;
    binarySearch(name, l, r, target, counter);
  }
  {
    int counter = 0;
    char target = 'e';
    int l = 0;
    int r = name.length() - 1;
    binarySearch(name, l, r, target, counter);
  }
  {
    int counter = 0;
    char target = 'i';
    int l = 0;
    int r = name.length() - 1;
    binarySearch(name, l, r, target, counter);
  }
}

void sortName(string &name)
{
  int range = name.length();
  char tmp;
  for (int j = 1; j < range; j++)
  {
    for (int i = 0; i < range - j; i++)
    {
      if (tolower(name[i]) > tolower(name[i + 1]))
      {
        tmp = name[i + 1];
        name[i + 1] = name[i];
        name[i] = tmp;
      }
    }
  }
}

int binarySearch(string name, int l, int r, char target, int counter)
{
  if (r >= l)
  {
    int mid = (l + r) / 2;
    counter++;

    if (tolower(name.at(mid)) == target)
    {
      cout << "Found " << target << " in " << counter << " tries." << endl;
      return mid;
    }
    if (tolower(name.at(mid)) > target)
    {
      return binarySearch(name, l, mid - 1, target, counter);
    }
    else
    {
      return binarySearch(name, mid + 1, r, target, counter);
    }
  }
  cout << "There are no " << target << "'s in this name." << endl;
  return -1;
}
