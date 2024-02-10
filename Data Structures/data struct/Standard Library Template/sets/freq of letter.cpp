#include <iostream>
#include <string>
#include <set>
#include <cctype>

using namespace std;

int main()
{
    string str = "Hello world";
    set<char> freq;

    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
        {
            freq.insert(str[i]);
        }
    }

    cout << "Unique letters: ";
    for (auto itr = freq.begin(); itr != freq.end(); itr++)
    {
        cout << *itr;
    }

    return 0;
}