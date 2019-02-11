#include <iostream>
using namespace std;

int getUserInput();
//double calcMean();
//double calcSD();

int getUserInput(){
    int value;
    cout << "Please enter a whole number." << endl;
    cin >> value;
    return value;
}



int main(){
    int NumberArray[10];
    for(int i = 0; i < 10; i++)
    {
        NumberArray[i]=getUserInput();
    }
    cout << "The array: " << endl;
    for(int j = 0; j < 10 ; j++)
    {
        cout << j+1 <<": "<< NumberArray[j] << endl;
    }
    return 0;
}



