#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    vector<string> strs;
    string temp;

    cout << "Enter inputs (0 to stop): ";
    while (cin >> temp && temp != "0")
    {
        strs.push_back(temp);
    }

    string smol = (strs.front());
    for (auto str : strs)
    {
        if (smol.length() > str.length())
        {
            smol.assign(str);
        }
    }

    for (auto str : strs)
    {
        while (str.find(smol) == str.npos) //  npos means didnot return anything
        {
            smol.pop_back();
        }
    }

    if (smol.length() > 0)
    {
        cout << "The common prefix is: " << smol << endl;
    }
    else
    {
        cout << "No common prefix" << endl;
    }

    return 0;
}