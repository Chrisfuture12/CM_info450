#include <iostream>
using namespace std;

int letters_minus_whitespace(char value[]);
int word_count(char[] value);

int main(){
    char str[] "some phrase of charecters that i went to count";
    cout << letters_minus_whitespace(str) << endl;

    
    return 0;
}

int letters_minus_whitespace(char value[]){
    int count = 0;
    cout << strlen(value) << endl;
    for(int i = 0; i < strlen(value); i++)
    {
        if(value[i] != " "){
            count++;
        }
    }
    
    return count;
}

int word_count(char[] value ){
    int count = 0;
    int word_count = 0;
    for(int i = 0; i < strlen(value); i++)
    {
        // series of letters
        // 1 char not including space or tab
        if (value[i] != " " && value[i] != "\t") {
            word_count++;
        } else {
            count++;
        }
        word_count = 0;
    }
    if (word_count > 0) {
        count++;
    }
}
