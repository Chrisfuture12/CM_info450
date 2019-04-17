#include <iostream>
using namespace std; // this allows every function to use cout

int userInP();
int stonetolb(int);
void display(int);

int userInP(){
    int value;
    cout << "Please enter the weight in stones" << endl;
    cin >> value; 
    return value;
}

int stonetolb(int sweight){
    return (14 * sweight);
}

void display(int n){
    cout << "the weight of the stones in pounds is: " << n << endl;
}

int main(){
    int stone;
    stone = userInP();
    int pounds = stonetolb(stone);
    display(pounds);
    return 0;
}




