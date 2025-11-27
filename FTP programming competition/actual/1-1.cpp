#include <bits/stdc++.h>
using namespace std;

string alpha = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
	int num;
	cout << "Input: ";
	cin >> num;

	cout << "Output: ";
	string str;

	int n = 0;
	while(num > 0) {
		int rem = (num % 27) + 1;
		num /= 27;
		str += alpha[rem-n];
		n++;
	}

	for(auto itr = str.rbegin(); itr != str.rend(); itr++) {
		cout << *itr;
	}
}