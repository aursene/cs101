#include <fstream>
#include <iostream>

using namespace std;

ofstream fOut;
ifstream fIn;

int main()
{
  cout << "Hello, User!" << endl;
  cin.get();
  string fName{""}, lName{""};


  fOut.open("./employee.txt", ofstream::out);
  for (int i; i < 3; i++)
  {
    cout << "Please enter your first name: ";
    cin >> fName;
    cout << "Now your last name: ";
    cin >> lName;


    fOut << fName[0] << "_" << lName << "@company.com" << endl;
  }
  fOut.close();

  cout << endl;

  cout << "Now, the emails for those employees:";
  fIn.open("./employee.txt", ios::in);
  while (!fIn.eof())
  {
    string email{""};
    fIn >> email;
    cout << endl << email;
  }
  fIn.close();
}
