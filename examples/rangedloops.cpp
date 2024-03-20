#include <iostream>
#include <vector>
using namespace std;

vector<int> num = {1, 5, 2, 7, 4, 9, 3};

int main()
{
  int size = num.size();
  cout << "Ranged Loop: " << endl;
  for (int i : num)
  {
    cout << i << ", ";
    cout << num[i] << endl;
  }
  cout << endl << endl << "Normal For Loop: " << endl;
  for (int i = 0; i < size; i++)
  {
    cout << i << ", ";
    cout << num[i] << endl;
  }
}
