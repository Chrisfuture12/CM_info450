#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstdio>
using namespace std;

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
    void set_type(type t){ 
        car_type = t;
    }
    enum type get_type() { return car_type; }
    void show();
};

//{"road_vehicle": "automobile", "wheels": 4, "passengers": 2, "type": "car"}
//{"road_vehicle": "truck", "wheels": 4, "passengers": 2, "cargo": 12000}

void road_vehicle::print(){
    if (vehicle_name == "truck"){
        cout << "{";
        cout << "\"road_vehicles\": ";
        cout << "\"truck\"";
        cout << ", ";
        cout << "\"wheels\": " << wheels;
        cout << ", ";
        cout << "\"passengers\": " << passengers;
        cout << ", ";
        cout << "\"cargo\": " << cargo; 
        cout << "}" << endl;
    } else if (vehicle_name == "automobile"){
        cout << "{";
        cout << "\"road_vehicles\": ";
        cout << "\"automobile\"";
        cout << ", ";
        cout << "\"wheels\": " << wheels;
        cout << ", ";
        cout << "\"passengers\": " << passengers;
        cout << ", ";
        cout << "\"type\": "<< "\"" << style <<"\""; 
        cout << "}" << endl;
    } if (next != NULL){
        next->print();
    }
}


int main(){
road_vehicle rv;
automobile c;
truck t1;

char str[255];
ifstream in;
in.open("output.txt");
  while(in) {
    in.getline(str, 255);  // delim defaults to '\n'
    if (strcmp(str, "truck") == 0){
        //cout << str << "*" << endl;
        in.getline(str,255); // Wheels
        string aar(str);
        string::size_type pos = aar.find(' '); // locate space
        string arg; 
        arg = aar.substr(pos + 1); // retrun string after space
        int i = std::stoi(arg); // parse
        t1.set_wheels(i);  
        in.getline(str,255); // passengers
        string bar(str);
        pos = bar.find(' '); // locate space 
        arg = bar.substr(pos + 1); // retrun string after space
        i = std::stoi(arg); // parse
        t1.set_passengers(i);
        in.getline(str,255); // cargo
        string car(str);
        pos = car.find(' '); // locate space
        arg = car.substr(pos + 1); // retrun string after space
        i = std::stoi(arg);
        t1.set_cargo(i); 
        t1.insert_vehicleT(t1.get_cargo());
    } else if (strcmp(str, "automobile") == 0){
        //cout << str << "*" << endl;
        in.getline(str,255); // wheels
        string aar(str);
        string::size_type pos = aar.find(' '); // locate space
        string arg; 
        arg = aar.substr(pos + 1);
        int i = std::stoi(arg);
        c.set_wheels(i);

        in.getline(str,255); // Passengers
        string bar(str);
        pos = bar.find(' '); // locate space 
        arg = bar.substr(pos + 1); // retrun string after space
        i = std::stoi(arg); // parse
        c.set_passengers(i);

        in.getline(str,255); // Type
        string car(str);
        pos = car.find(' '); // locate space
        arg = car.substr(pos + 1); // retrun string after space
        /*if (arg == "van"){
                c.set_type(van);
            } else if (arg == "car"){
                c.set_type(car);
            } else if (arg == "wagon"){
                c.set_type(wagon);
            }*/
        c.insert_vehicleA(arg);
    }
  } 
  t1.print();
  c.print();
return 0;
}