/* Week 15 Q1 Base Class

 @Adi Latic

 4/30/2024

 Global space -- Header Files
*/

#include "human.h"
#include <iomanip>
#include <iostream>

using namespace std;

class student : public Human
{
public:
  double gpa{2.0};

  student(string cname, int cage, int cweight, double cgpa)
  {
    name = cname;
    age = cage;
    weight = cweight;
    gpa = cgpa;
  }

  void display()
  {
    cout << "name: " << name;
    cout << "  ";
    cout << "age: " << age;
    cout << "  ";
    cout << "weight: " << weight;
    cout << "  ";
    cout << "gpa: " << setprecision(8) << gpa;
  }
};

int main()
{
  Human Adi("Adi", 18, 169);

  Adi.display();
  cout << "\n";

  Adi.age = 21;
  Adi.weight = 180;
  Adi.name = "Captain America";

  cout << "\nThe new Adi is now: "
       << "\n";
  Adi.display();


  cout << "\n\n\n";
  student Braxton("Braxton", 21, 210, 3.0);

  Braxton.display();
  cout << "\n\n";

  Braxton.age = 22;
  Braxton.weight = 175;
  Braxton.gpa = 4.0;
  Braxton.name = "Tony Stark";

  cout << "The new Braxton is now: "
       << "\n";
  Braxton.display();


  cout << "\n";
}
