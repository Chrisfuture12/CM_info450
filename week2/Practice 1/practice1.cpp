#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int pVal;
    do {
        cout << "Please enter a positive value: " << endl;
        cin >> pVal;
        cout << "Your value squared is: " << pow(pVal, 2) << endl;
    }
    while(pVal > 0);
    if (pVal == 0) {
        cout << "You entered a zero. End of execution" << endl;
    } else
    {
        cout << "You entered a negative number. The end" << endl;
    } 
    return 0;
}