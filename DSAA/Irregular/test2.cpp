#include <string>
#include <map>
#include <iostream>
using namespace std;

struct Comparator {
    bool operator()(const char &a, const char &b)const {
        return a < b;
    }
};

int main() {
    string str;
    map<char,int, Comparator> freq;
    cout << "Enter input: ";
    getline(cin,str);

    for(char c : str) {
        if(isalpha(c)) {
            freq[c]++;
        }
    }

    for(auto &[key,value] : freq) {
        cout << key << " : " << value << endl;
    }
    str.erase(1);
    cout << str;


}
