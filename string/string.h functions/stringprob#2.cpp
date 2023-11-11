#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<string> mySet;
    string temp;

    cout << "Enter inputs:\n";
    while (cin >> temp && temp != "0")
    {
        mySet.insert(temp);
    }

    cout << "\nOutput: ";
    mySet.reserve(mySet.size());

    for (auto itr : mySet)
    {
        cout << itr << " ";
    }

    return 0;
}