#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    string str = "Hello World";
    map<char, int> freq;

    // for (int i = 0; i < str.length(); i++)
    // {
    //     if (freq.find(str[i]) == freq.end()) // if it is NOT found
    //     {
    //         freq[str[i]] = 0; // initializing to zero
    //     }
    //     freq[str[i]]++;
    // }
    
    for(int i=0;i<str.length();i++){

        freq[str[i]]++;
    }

    for (auto itr = freq.begin(); itr != freq.end(); itr++){
        cout << itr->first << ":" << itr->second << endl;
    }

    return 0;
}
