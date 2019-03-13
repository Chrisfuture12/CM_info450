#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdio>
using namespace std;

class Employee {
    private:
        char first_name[255]; // First Name
        char last_name[255]; // Last Name   
        bool employee_type;
        int compensation = 0;

    public:
        void set_first_name( char* in_name){ 
            strcpy(first_name, in_name);
        }
        void set_last_name( char* in_name){ strcpy(last_name, in_name);}
        void set_employee_type(bool in_p){ employee_type = in_p;}
        
        void printEntry(){
        if (!employee_type){
            cout << last_name << ", ";
            cout << first_name << ": " << "Annual Compensation " << endl;
        } else {
            cout << last_name << ", ";
            cout << first_name << ": " << "Hourly Compensation " << endl;
        }
    }
};

int main() {
    const int MAX = 3;
    Employee entries[MAX];

    for (int x = 0; x< MAX;x++){
      cout << "Entry: " << x << endl;
      char *myvalue = (char *)malloc(255);

      cout << "Enter a first name: ";
      cin.getline(myvalue,255);
      entries[x].set_first_name(myvalue);
      cout << "Entered value: " << myvalue << endl;

      cout << "Enter a last name: ";
      cin.getline(myvalue,255);
      entries[x].set_last_name( myvalue );
 
      cout << "Enter the type of compesation, either 'HOURLY' or 'EXEMPT'";
      cin.getline(myvalue,255);
      if (myvalue == "EXEMPT"){
        entries[x].set_employee_type(false);
      } else if (myvalue == "HOURLY"){
        entries[x].set_employee_type(true);
      }
      
    } 

    for (int x = 0; x< MAX;x++){
        entries[x].printEntry();
    }

    return 0;
}