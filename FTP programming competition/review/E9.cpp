#include <bits/stdc++.h>
using namespace std;

bool isPalin(string &str) {
	int n = str.size();
	for (int i = 0; i < n / 2; i++) {
		if ( str[i] != str[n - i - 1])
			return false;
	}
	return true;
}

bool isPalin1(string &str){
	int i=0, j= str.size()-1;
	while (i < j){
		while(!isalpha(str[i]) && i < j){
			i++;
		}
		while(!isalpha(str[j]) && i < j){
			j--;
		}
		if(str[i] != str[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main() {
	string str;
	getline(cin, str);
	cout << (isPalin1(str) ? "YES" : "NO");
}
