#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;
bool ccChecker (string& a){
    int secondCheck = false;
    int nDigit = a.size();

    int sum = 0;

    for( int i = nDigit -1 ; i >= 0; i--){
         int digit = a[i] - '0'; // convert string into int

        if (secondCheck == true){
            digit = digit * 2;
            if( digit > 9)
                digit = digit -9;

            sum += digit;

        }

        secondCheck = !secondCheck;
    }

     return sum % 10;
}
int main()
{
     string a = "46447474747474";
     //a[2] = '\0'; // ignores the value in that particular array [2] and prints out space (" ")

     if(ccChecker(a) == false){
         cout<<"Its a valid Mastercard"<<endl;
     }
     else {
         cout<<"Its not a Mastercard"<<endl;
     }

     //cout with ternary operator (?)
     string ok = "Its a valid Mastercard";
     string nok = "Its not a Mastercard";
     ccChecker(a) == 0 ? cout<< ok : cout<<nok;

     return 0;
 }


