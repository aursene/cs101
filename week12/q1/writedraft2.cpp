#include <cctype>
#include <fstream>
#include <iostream>
using namespace std;

ofstream test1;

string temp;

int main()
{
  test1.open("./testFile.txt",
             ios::out); // Used to open the file "testFile.txt" in the test1 stream, while setting it to "out" mode
                        // (write mode) Other modes include: ios::in - input mode, or read mode

  // A simple if statement to ensure that, if the file wasn't opened, an error message is sent to the user
  if (!test1)
  {
    cerr << "Error opening file ";
    exit(EXIT_FAILURE);
  }

  test1 << "Braxton Beckman" << endl; // sends my name to the fstream,

  string name{"testing1"};

  while (true)
  {
    cout << "\nenter a name or \"quit\" to quit ";
    cin >> name;
    if (name == "quit")
      break;
    test1 << name << "\n";
  }

  test1.close();

  ifstream test2;

  test2.open("./testFile.txt", ios::in);

  while (!test2.eof())
  {
    test2 >> temp;
    cout << temp << endl;
  }
}
