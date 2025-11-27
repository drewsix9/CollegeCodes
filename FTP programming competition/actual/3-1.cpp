#include <bits/stdc++.h>
using namespace std;

map<char, int> hash = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int RomanToInt(string str) {
	int res = 0;
	for(int i =0; i<str.size(); i++) {
		char curr = str[i];
		char nxt = str[i+1];
		if(hash[curr] < hash[nxt]) {
			res += hash[nxt] - hash[curr];
		} else {
			res += hash[curr];
		}
	}
	return res;
	
}

int main() {
	string str;
	cout << "Enter roman numeral: ";
	cin >> str;
	cout << "\nOutput: " << RomanToInt(str);
	
}
