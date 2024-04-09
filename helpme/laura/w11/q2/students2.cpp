
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "students2.h"



// using Java coupling so classes can work together to run program 
string students2::getName()
{

	return _Name; 

}


double students2::getGpa()
{

	return _Gpa; 

}

string students2::getCourse()
{

	return _Name;

}


void students2::setGpa(double _cGpa)
{

	_Gpa = _cGpa; 
	bool flag = true;

	if (_Gpa > 3.0)
	{
		cout << "true: " << flag;

		_Gpa = _cGpa;


	}
	
	else
	{
		_Gpa = _cGpa; 
	}
	

}


void students2::setCourse(string& _cCourse)
{
	_Course = _cCourse; 

	vector<string>course; 

	course.push_back(_Course); 


}

void students2::display()
{
	cout << "\nName: " << _Name; 
	cout << "\nGpa: " << _Gpa; 
  cout << "\nCourses: " << _Course; 

}