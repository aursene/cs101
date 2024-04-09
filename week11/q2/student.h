#pragma once
#include <string>
#include <vector>

class student
{
public:
  student();

  bool approval(double gpa); // checks if gpa > 3.0; returns 1 if true, 2 if false
  void display();            // displays values of all private variables
  double getGpa();
  void setGpa(double newGpa);
  std::string getName();
  std::string getClasses();
  void addClass(std::string newClass);

private:
  std::string name{"a"};
  double gpa{0.1};
  std::vector<std::string> classes{};
};
