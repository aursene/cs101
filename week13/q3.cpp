#include <iostream>
using namespace std;

void func(int *);

int main()
{
  int arr[5]{1, 2, 3, 4, 5};
  int *pArr = arr;

  for (int i = 0; i < 5; i++)
  {
    cout << arr[i] << ", ";
  }
  cout << endl;
  func(pArr);

  for (int i = 0; i < 5; i++)
  {
    cout << *pArr << ", ";
    pArr++;
  }
  cout << endl;
}

void func(int *fArr)
{
  for (int i = 0; i < 5; i++)
  {
    *fArr *= 3;
    fArr++;
  }
  cout << endl;
}
