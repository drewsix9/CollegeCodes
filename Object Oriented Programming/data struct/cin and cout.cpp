#include <iostream>

using namespace std;

int main()
{
    int size = 0;
    cout << "Enter input number of inputs: ";
    cin >> size;
    cin.ignore(1000, '\n'); // fflush in cpp

    string str;
    cout << "\nEnter string: ";
    getline(cin, str); // gets in cpp
    cout << size << endl;
    cout << endl;
    cout << str;

    return 0;
}
