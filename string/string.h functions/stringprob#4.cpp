#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input;
    string vowels = "aeiouAEIOU";
    vector<string> strs;

    cout << "Enter string (0 to stop): ";

    while (cin >> input && input != "0")
    {
        strs.push_back(input);
    }

    int maxVowel = 0;
    string max;
    for (auto str : strs)
    {
        int count = 0;
        auto pos = str.find_first_of(vowels);
        while (pos != string::npos)
        {
            count++;
            pos = str.find_first_of(vowels, pos + 1);
        }
        if (maxVowel < count)
        {
            maxVowel = count;
            max = str;
        }
    }

    cout << "\nWord with the most vowels is "
         << "\"" << max << "\""
         << " with " << maxVowel << " vowels";

    return 0;
}