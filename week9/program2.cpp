#include <iostream>
#include <fstream>
using namespace std;

int main(){

char str[255];
ifstream in;
in.open("test.txt");

  while(in) {
    in.getline(str, 255);  // delim defaults to '\n'
    cout << "LINE:*" << str << "*" << endl;
  } 
return 0;
}