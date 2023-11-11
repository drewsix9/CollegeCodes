#include <iostream>
#include <string>

using namespace std;

int main()
{ //               01234
    string word = "hello";
    string vowels = "aeiouAEIOU";
    string token;

    auto pos = 0;
    pos = word.find_first_of(vowels);

    while (pos != string::npos)
    {
        token = word.substr(pos);
        cout << token << endl;

        pos = word.find_first_of(vowels, pos + 1);
    }

    return 0;
}