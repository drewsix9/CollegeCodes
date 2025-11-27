#include <bits/stdc++.h>
using namespace std;

bool check(string str, string ref) {
	string newStr;
	for(char c:str) {
		newStr += tolower(c);
	}
	for(char c : newStr) {
		if(ref.find_first_of(c) == string::npos) {
			return false;
		}
	}
	return true;
}

int main() {
	string r1 = "qwertyuiop";
	string r2 = "asdfghjkl";
	string r3 = "zxcvbnm";

	string input, tmp;
	cout << "Enter input: ";
	getline(cin, input);
	stringstream ss(input);
	vector<string> strs;
	while(ss >> tmp) {
		strs.push_back(tmp);
	}

	cout << "Output: ";
	for(string s : strs) {
		if(check(s, r1) || check(s, r2) || check(s, r3)) {
			cout << s << " ";
		}
	}
}