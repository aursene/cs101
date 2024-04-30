#include <iostream>
using namespace std;

void func(int *, char *);

int main()
{
  int num{5};
  char letter{'a'};

  int *numPointer = &num;
  char *letterPointer = &letter;

  cout << "Our number is " << num << "\nOur letter is " << letter << endl << endl;

  func(numPointer, letterPointer);

  cout << "After sending them to the function,"
       << "\nOur number is " << *numPointer << "\nOur letter is " << *letterPointer << endl;
}

void func(int *nNum, char *nChar)
{
  *nChar = *nChar + 1;
  *nNum = *nNum * 3;
}
