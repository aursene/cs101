#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  char data[22];
  ifstream file1; // declares file1 as an input stream reading from a file
  file1.open("/home/braxton/testFile.txt", ios::in);

  cout << "\nReading testFile.txt" << endl;

  while (!file1.eof()) // Reads data from an open file designated in the file1 declaration
  {
    file1 >> data;
    cout << data << endl;
  }

  file1.close();
  return 0;
}
