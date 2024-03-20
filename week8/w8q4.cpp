#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<string> name;
int brk{};

int main()
{
  cout << "Please enter some names (enter \"stop\" to quit): ";
  while (brk == 0)
  {
    string tmp;
    cin >> tmp;
    if (tmp == "stop")
      break;
    name.push_back(tmp);
  }

  sort(name.begin(), name.end());
  cout << "\nThis is the sorted vector: \n";
  for (string k : name)
  {
    cout << k << endl;
  }

  cout << "\nNow let's pop the vector: " << endl;
  name.pop_back();
  for (string k : name)
  {
    cout << k << endl;
  }
}
