#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    int input, n , ans = 1, count, rem, sum, temp;
    cout << "Enter how many inputs: " << endl;
    cin >> input;

    cout << "Enter the inputs: " << endl;
    for(int i = 0;i<input;i++){
        cin >> n;
        temp = n;
        rem = 0;
        sum = 0;
        ans = 1;

        // Loop to add sum of input
        while(temp>0){
            rem = temp%10;
            sum = sum+rem;
            temp  = temp/10;
        }
        for(int j=2;j<sum;j++){
             if(sum%j == 0){
                 ans = 0;
             }else {
                 break;
             }
        }
        if(ans){
            cout << n << endl;
        }else{
            cout << "Sum of each digit per input is not prime" << endl;
        }

    }
    return 0;
}