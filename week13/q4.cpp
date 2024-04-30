#include <iostream>
#include <vector>
using namespace std;

int searchString(string);
vector<char> vowels{};

int main()
{
  string name{};
  cout << "Please enter your name: ";
  getline(cin, name);

  cout << "There are " << searchString(name) << " vowels in your name, and they are ";

  for (int i = 0; i < vowels.size(); ++i)
  {
    cout << vowels[i];
    if (i == vowels.size() - 1)
    {
      cout << " ";
    }
    else
    {
      cout << ", ";
    }
  }
  cout << "\n";
}

int searchString(string tName)
{
  char *pName = &tName[0];

  for (int i = 0; i < tName.size(); i++)
  {
    if (tolower(*pName) == 'a' || tolower(*pName) == 'e' || tolower(*pName) == 'i' || tolower(*pName) == 'o' ||
        tolower(*pName) == 'u')
    {
      vowels.push_back(*pName);
    }
    pName++;
  }
  return vowels.size();
}
