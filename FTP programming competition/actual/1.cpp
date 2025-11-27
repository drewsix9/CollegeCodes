#include <bits/stdc++.h>
using namespace std;

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
	int num;
	cout << "Input: ";
	cin >> num;

	cout << "Output: ";
	string str;

	int n = 0;
	while(num > 0) {
		int rem = num % 26;
		num /= 26;
		str += alpha[rem-1];
	}

	for(auto itr = str.rbegin(); itr != str.rend(); itr++) {
		cout << *itr;
	}
}