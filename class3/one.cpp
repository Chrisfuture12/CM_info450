#include <iostream>
#include <cmath>

using namespace std;
bool isOdd(int value);
int main(){

    bool return_value = true;
    int my_number = 0;
    cout << "give me a numer: ";
    cin >> my_number;
    return_value= isOdd(my_number);

    if (outside_value == true ){
        cout << "my number is certainly odd." << endl;
    } else {
        cout << "it is Nt ODD." << endl;
    }
    cout << "inside value: " << return_value
    return 0;
} 

bool isOdd(int value){
    bool return_Value;
    return_value = (value % 2 ==1);
    return return_value;
}