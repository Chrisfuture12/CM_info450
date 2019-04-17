#include <iostream>
#include <cstdio>
using namespace std;

struct inflatable{ // Inflatable is the new type which contains the following data types. Here we have an external struct.
    char name[20];
    float volume;
    double price;
    bool is_private;
};
void print_entry(inflatable *x);

void print_entry(inflatable *x, inflatable *y){
    if (x->is_private == false) {
        cout << "Expand your guest list with " << x->name << endl;
        cout << "You can have this for $" << x->price << endl;
        cout << "Is this a private account: '0' = No. '1' = Yes. Status: "<< x->is_private << endl;
    }
    if (!x->is_private){
        cout << "Car name: " << y->name << ". Is equal to the Guest name: " << x->name << "." << endl;
    }
}

int main(){
    inflatable guest = {
        "Chris Morris",
        152.2,
        22,
        false
    }; // Guest is a stucture variable of type inflatable.
    inflatable car;
    car = guest; // Memberwise assignment
    print_entry(&guest, &car);


    
    return 0;
}
