#include <iostream>
using namespace std;

int main()
{
    int pNum, i, count = 0;    
    do 
    {
        cout << "Please enter a prime number: " << endl;
        cin >> pNum;
        if (pNum== 0)
        {
            cout << "\n" << pNum<< " is not prime" << endl;
            exit(1);
        }
        else   {
                for(i=2; i < pNum; i++)
                    if (pNum% i == 0)
                        count++;
        }
        if (count > 1)
        {
 	        cout << "\n" << pNum<< " is not prime." << endl;
        }
        else 
        {
            cout << "\n" << pNum<< " is prime." << endl;   
        } 
    }
        while(pNum > 0);    
    return 0;
}