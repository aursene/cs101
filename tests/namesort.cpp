#include <iostream>
#include <string>

using namespace std;

int main()
{
  int i = -1, j, k;
  char tmp;

  string name = "Capulet";
  i = name.length();

  for (j = 1; j <= i; j++)
  {
    for (k = 0; k < i - 1; k++)
    {
      if (name[k] > name[k + 1])
      {
        tmp = name[k];
        name[k] = name[k + 1];
        name[k + 1] = tmp;
      }
    }
  }
  for (int p = 0; p < i; p++)
  {
    cout << name[p];
  }
  cout << endl;
}
