#include <bits/stdc++.h>
using namespace std;

int main() {
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int num;
	string str;
	cout << "Input: ";
	cin >> num;
	cout << "Output: ";

	while (num > 0) {
		num--;
		int rem = num % 26;
		num /= 26;
		str += alpha[rem];
	}

	reverse(str.begin(), str.end());

	cout << str;
}
