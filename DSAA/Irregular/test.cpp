#include <bits/stdc++.h>
using namespace std;

struct Comparator {
	bool operator()(const char &a,const  char &b) const {
		return a < b;
	}
};

int main() {
	map<char, int, Comparator> freq;
	string str;
	cout << "Enter string: ";
	getline(cin,str);
	for(char c:str) {
		if(isalpha(c))
			freq[c]++;
	}

	for(auto &[key,value]: freq) {
		cout << key << " : " << value << endl;
	}


}
