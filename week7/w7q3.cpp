/*
Braxton Beckman Week 7
Question 3: Efficient Bubble sort
Objective: Take a user's name and sort it alphabetically using a more efficient bubble sort, then input 3 numbers and
sort them in descending order
*/

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

void eBubble(int[], int);
void letSort(string &);

string name;
int scores[3] = {5, 1, 9};
int tmp;
int size{5};
char tmp2;

int main()
{
  cout << "Please enter your name: ";
  cin >> name;
  cout << "Please enter your 3 scores: ";
  cin >> scores[0] >> scores[1] >> scores[2];
  int length = name.length();
  cout << "\n";

  // sorts then displays the given scores in the array
  eBubble(scores, 4);
  cout << "Here are the sorted scores: ";
  for (int k = 0; k < 3; k++)
  {
    cout << scores[k];
    if (k == 2)
    {
      cout << "." << endl;
    }
    else
    {
      cout << ", ";
    }
  }

  letSort(name);
  cout << "Here is your name sorted alphabetically: ";
  for (int l = 0; l < length; l++)
  {
    cout << name[l];
  }
  cout << endl;
}

// uses efficient bubble sorting to sort the scores in descending order
void eBubble(int scores[3], int size)
{
  for (int j = 1; j < size; j++)
  {
    for (int i = 0; i < size - 1 - j; i++)
    {
      if (scores[i] < scores[i + 1])
      {
        tmp = scores[i];
        scores[i] = scores[i + 1];
        scores[i + 1] = tmp;
      }
    }
  }
}

// catches the address of variable string name and uses efficient bubble sorting to sort the letters in alphaetical
// order
void letSort(string &name)
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
}
