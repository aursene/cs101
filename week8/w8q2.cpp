#include <iostream>
using namespace std;

string name1, name2;
string sortedName1, sortedName2;
string tmpCommonLetters, commonLetters;

string letterSort(string);

void compare(string, string);
// void cleanup(string);

int main()
{
  cout << "Please enter two names: ";
  cin >> name1 >> name2;

  compare(letterSort(name1), letterSort(name2));
  // cleanup(tmpCommonLetters);
  cout << "\nThe common letters in these names are: " << commonLetters << "\n\n";
}

string letterSort(string name)
{
  char tmp;
  int length = name.length();
  for (int o = 1; o < length; o++)
  {
    for (int p = 0; p < length - o; p++)
    {
      if (tolower(name[p]) > tolower(name[p + 1])) // uses tolower() function to ensure no errores with capital letters
      {
        tmp = name[p + 1];
        name[p + 1] = name[p];
        name[p] = tmp;
      }
    }
  }
  return name;
}

void compare(string n1, string n2)
{
  int nl1 = n1.length();
  int nl2 = n2.length();

  for (int i = 0; i < nl1; i++)
  {
    for (int k = 0; k < nl2; k++)
    {
      if (tolower(name1[i]) == tolower(name2[k]))
      {
        if (commonLetters.find(name1[i]) != string::npos)
          continue;
        else
          commonLetters += name1[i];
      }
    }
  }
}

/* void cleanup(string letters)
{
  commonLetters += letters[0];
  int lng = letters.length();
  for (int i = 0; i < lng; i++)
  {
    int lng2 = commonLetters.length();
    for (int k = 0; k < lng2; k++)
    {
      if (tolower(letters[i]) == tolower(commonLetters[k] || tolower(commonLetters[k + 1])))
      {
        cout << "FALSE and " << commonLetters << endl;
        break;
      }
      else
      {
        cout << "TRUE and " << commonLetters << endl;
        commonLetters += tolower(letters[i]);
      }
    }
  }
}*/
