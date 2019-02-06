#include <iostream>
using namespace std;

char  get_user_input();
void to_upper_case(char &letter);
int main(){
  char user_input_letter;
  cout << "Type in a letter grade, lowercase or uppercase." << endl; 
  if ('0' != (user_input_letter = get_user_input())){
    to_uppser_case(user_input_letter);
    switch (user_input_letter){
      case 'A': cout << "Super Great job on an A!" << endl;break;
      case 'B': cout << "Great job on a B!" << endl;break;
      case 'C': cout << "Good job on a C!" << endl;break;
      case 'D': cout << "Keep at it, you can get there." << endl;break;
      case 'F': cout << "F is for #fail" << endl;break;
      default : cout << "This is not a valid grade: " << user_input_letter << endl;
    }
  }
  cout << "You have entered 0.  Exiting." << endl; 
}
char  get_user_input(){
    char letter;
    cout << "Enter letter: ";
    cin >> letter;
    return;
}
void to_upper_case(char &letter){
   if(letter = "a"){
      letter = "A";
      return;
   } else if (letter = "b"){
      letter = "B";
      return;
   } else if (letter = "c"){
      letter = "C";
      return;
   } else if (letter = "d"){
      letter = "D";
      return;
   }else if(letter = "f"){
      letter = "F";
      return;
   }

}