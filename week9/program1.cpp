#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdio>  
#include <fstream>     
using namespace std;     

// base class for vehicles
class road_vehicle{
private:
    string vehicle_name;
    int wheels;
    int passengers;
    int cargo;
    string style;
public:
    road_vehicle *next;
    road_vehicle(){
        next = NULL;
    }

    void set_wheels(int num){
        wheels = num;
    }    
    int get_wheels(){
        return wheels;
    }
    void set_passengers(int num){
        passengers = num;
    }
    int get_passengers(){
        return passengers;
    }
    void show(); //not yet defined!
    void insert_vehicleA(string instyle);
    void insert_vehicleT(int cargo);
    void print();
};

void road_vehicle::insert_vehicleA(string instyle){
    string n = "automobile";
    int w = get_wheels();
    int p = get_passengers();
    string t = instyle;
        if (next == NULL){
            next = new road_vehicle;
            next->wheels = w;
            next->passengers = p;
            next->vehicle_name = n;
            next->style = t;
        }else{
            next->insert_vehicleA(instyle); // Always start from 1st node and recurrsive
        } 
} 
void road_vehicle::insert_vehicleT(int cargo){
    string n = "truck";
    int w = get_wheels();
    int p = get_passengers();
    int c = cargo;
        if (next == NULL){
            next = new road_vehicle;
            next->wheels = w;
            next->passengers = p;
            next->cargo = c;
            next->vehicle_name = n;
        }else{
            next->insert_vehicleT(cargo); // Always start from 1st node and recurrsive
        } 
}

void road_vehicle::print(){  
    ofstream out;
    out.open("output.txt", std::ios::app);
    if (!out){
    cout << "Cannot open file." << endl;
    //return 1;
    }
    if (!out.is_open()){
    cout << "File is not open." << endl;
    //return 2;
    }
    if (vehicle_name == "truck"){
        out << "truck" << endl;
        out << "wheels: " << wheels << endl;
        out << "passengers: " << passengers << endl;
        out << "cargo: " << cargo << endl;
    } else if (vehicle_name == "automobile"){
        out << "automobile" << endl;
        out << "wheels: " << wheels << endl;
        out << "passengers: " << passengers << endl;
        out << "type: " << style << endl;
    }
        if (next != NULL){
        next->print();
    } else if (next == NULL) {
        out.close(); 
    }
}


//Define a truck
class truck : public road_vehicle {
private:
    int cargo;
public:
    void set_cargo(int size){
        cargo = size; 
    }
    int get_cargo(){
        return cargo;
    }
    void show();
};

enum type {car, van, wagon};

class automobile : public road_vehicle {
    enum type car_type;
public:
    void (type t){ 
        car_type = t;
    }
    enum type get_type() { return car_type; }
    void show();
};



int main(){
    road_vehicle rv;
    automobile c;
    truck t1;
    
    char *myvalue  = (char *)malloc(255);
    char *again = (char *)malloc(255);
    
    do {
        cout << "Is this an automobile or a truck? Enter 'automobile' or 'truck'" << endl;
        cin.getline(myvalue,255);
        if (strcmp(myvalue, "automobile") == 0){
           // char vehicle[255];
            int wheel;
            int passengers;
            char type[255];
            cout << "How many wheels does this vehicle have?" << endl;
            cin >> wheel;
            c.set_wheels(wheel);
            cout << "How many passengers can this vehicle hold?" << endl;
            cin >> passengers;
            c.set_passengers(passengers);
            cout << "What type of automobile is this?   Enter van, car or wagon" << endl;
            cin >> type;
            if (type == "van"){
                c.set_type(van);
            } else if (type == "car"){
                c.set_type(car);
            } else if (type == "wagon"){
                c.set_type(wagon);
            }
            c.insert_vehicleA(type);
        } else if (strcmp(myvalue, "truck") == 0){
            int wheel;
            int passengers;
            int cargo;
            cout << "How many wheels does this vehicle have?" << endl;
            cin >> wheel;
            t1.set_wheels(wheel);
            cout << "How many passengers can this vehicle hold?" << endl;
            cin >> passengers;
            t1.set_passengers(passengers);
            cout << "How much cargo (in pounds) can this vehicle hold?" << endl;
            cin >> cargo;
            t1.set_cargo(cargo);
            t1.insert_vehicleT(t1.get_cargo());
        } else {
            cout << "Wrong entry" << endl;
            break;
        }
        cout << "Would you like to enter another vehicle? yes or no" << endl;
        cin.getline(again,255);
        cin.getline(again,255);
    } while (strcmp(again, "yes") == 0); 
    c.print();
    t1.print();
    return 0;
}
