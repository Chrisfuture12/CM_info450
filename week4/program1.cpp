#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;


int getUserInput();
double calcMean(int numbers[]);
double calcSD(int numbers[], double mean);

int getUserInput(){
    int value;
    cout << "Please enter a whole number." << endl;
    cin >> value;
    return value;
}

double calcMean(int numbers[]){
    int sum = 0;
    double mean;
    for(int i = 0; i < 10; i++)
    {
      sum += numbers[i]; 
    }
    mean = double(sum)/10;
    return mean;
}
double calcSD(int numbers[], double mean){
    double sigma=0;
    double standevn;
    //double value1;
    for(int i = 0; i < 10; i++)
    {
        //value1 = numbers[i]-mean;
        sigma += pow(numbers[i]-mean, 2);
    }
    standevn  = sqrt(sigma/10);
}




int main(){
    int NumberArray[10];
    double mean;
    double standev;
    for(int i = 0; i < 10; i++)
    {
        NumberArray[i]=getUserInput();
    }
    cout << "The array: " << endl;
    for(int j = 0; j < 10 ; j++)
    {
        cout << j+1 <<": "<< NumberArray[j] << endl;
    }

    mean = calcMean(NumberArray);
    cout << "The mean value is: " << mean << endl; 

    standev = calcSD(NumberArray, mean);
    cout << "The standard deviation is: " << standev << endl; 


    return 0;
}



