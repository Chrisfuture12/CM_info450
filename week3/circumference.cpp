#include <iostream>
using namespace std;
double calculateCircumference(int);
const float PI = 3.14159265358979323846;

int main(){
    int value1;
    cout << "Enter a radius of a circle " << endl;
    cin >> value1;
    cout << "The circumfrance is: "<< calculateCircumference(value1) << endl;
}

double calculateCircumference(int radius){
   return (2*PI*radius);
}
