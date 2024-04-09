#pragma once
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

class students2
{
	

public:

	students2(string _name, double _gpa,string _course) //contructor 
	{
		_Name = _name; 
		_Gpa = _gpa; 
		_Course = _course; 
	}

	

	string getName(); 
	double getGpa(); 
	string getCourse(); 
	void setGpa(double); 
	void setCourse(string&);
	void display(); 
	

private:

	string _Name; 
	double _Gpa; 
	string _Course;
	
};

