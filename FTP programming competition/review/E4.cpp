#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cout << "Input:" << endl;
	getline(cin, str);
	cout << "Output:" << endl;
	for( auto itr = str.rbegin(); itr != str.rend(); itr++){
		cout << *itr;
	}
}
