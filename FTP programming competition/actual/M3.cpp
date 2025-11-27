#include <bits/stdc++.h>
using namespace std;

bool isPal(string &str) {
	int i = 0, j = str.size() - 1;
	while ( i < j ) {
		if (str[i] != str[j]) {
			if (str[i + 1] == str[j]) {
				i++;
			} else if (str[i] == str[j - 1]) {
				j--;
			} else {
				return false;
			}
		}
		i++;
		j--;
	}
	return true;
}

int main() {
	string str;
	cout << "Input: ";
	cin >> str;
	cout << "Output: ";
	if (isPal(str) == true) {
		cout << "True";
	} else {
		cout << "False";
	}
}
