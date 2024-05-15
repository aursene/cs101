/* Week 15 Q1 Base Class

 @Adi Latic

 4/30/2024

 Global space -- Header Files
*/

#include <iostream>
#pragma once

using namespace std;

class Human {
public:
	string name;
	int age;
	int weight;

	Human() {

	}
	
	Human(string cname, int cage, int cweight) {
		name = cname;
		age = cage;
		weight = cweight;
	}

	void display() {
		cout << "name: "<< name;
		cout << "  ";
		cout << "age: " << age;
		cout << "  ";
		cout << "weight: " << weight;
	}
};
