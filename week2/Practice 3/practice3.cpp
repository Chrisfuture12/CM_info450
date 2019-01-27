#include <iostream>
using namespace std;

int main()
{
    int yVal;
    do 
    {
        cout << "Enter a year: " << endl;
        cin >> yVal;

        if (yVal % 4 == 0)
        {
            if (yVal % 100 == 0)
            {
                if (yVal % 400 == 0){
                    cout << yVal << " is a leap year." << endl;
                }
                else {
                    cout << yVal << " is not a leap year." << endl;
                }
            }
            else 
            {
                cout << yVal << " is a leap year." << endl;

            }
        }
        else
            cout << yVal << " is not a leap year."<< endl;
    }
    while(yVal > 0);    
    return 0;
}