
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "students2.h"


int main()
{
    

    cout << "\ndefault: ";
    students2 D{ "a",0.1, "comsci"};
    D.display(); 
    cout << endl; 

    cout << "\nStudents info: ";
    students2 scholar{ "sandy",2.0, "biology,anatomy,satistics" };
    
    //checking if setters/getters work 
    cout << "\nName: " << scholar.getName();
    cout << "\nGpa: " << scholar.getGpa() << endl; 
    
    cout << "\nmodifying GPA: ";
     scholar.setGpa(2.5); 
     scholar.display(); 

     
     char choice = ' ';
     double gpaEntered;
     string coursechoice; 
      
     while (choice != 'q')
     {
         cout << "\n\nEnter (g)pa or (q)uit (c)ource: ";
         cin >> choice ; 

         if ('g' == choice)
         {
             cout << "\nEnter gpa: ";
             cin >> gpaEntered; 
             scholar.setGpa(gpaEntered); 
             scholar.display(); 
         }

         if (choice == 'c')
         {
             cout << "\nEnter course: "; 
             cin >> coursechoice;
             scholar.setCourse(coursechoice);
             scholar.display(); 
             

         }

        

     }

  
     cout << endl; 


     return 0; 
}
