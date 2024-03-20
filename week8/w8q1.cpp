#include <iostream>
#include <limits>
using namespace std;

string prompt{"Please enter a score from 1-100: "};

int protectData(string);

int main()
{
  for (int i = 0; i < 3; i++)
  {
    int finalscore = protectData(prompt);
    cout << "The score you entered is " << finalscore << endl << endl;
  }
}

int protectData(string prompt)
{
  int score;
  cout << prompt;
  cin >> score;
  while (score < 1 || score > 100 || cin.fail())
  {
    while (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "That was an invalid score, please reenter a valid score: ";
    cin >> score;
  }
  return score;
}
