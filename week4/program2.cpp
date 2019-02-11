#include <iostream>
using namespace std;

int main(){

    string nameArray[5][5] = {
                        {"Sequan","Chris","Mohmed","madiha","hunter"},
                        {"joshua","adam","Andrew","Alexandra","Patrick"},
                        {"Rudy","Jenish","Shaswat","Hafsa","Glenn"},
                        {"Arthur","Stone","Trang","Katelyn","Allen"},
                        {"Marquis","Omar","Zeeshan","Omar","Zeeshan"}    
    };
    cout << "Please press enter for class list." << endl;
    if (cin.get() == '\n')
    {
        int row; 
        int col;
        for (row = 0;row < 5;row++){
            for (col = 0;col < 5; col++){
                cout << nameArray[row][col] << endl;
            }
        } 
    } else {
        "You did not follow the command. The End.";
    }
    return 0;
}