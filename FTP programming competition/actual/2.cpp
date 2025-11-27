#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> n1;
	vector<int> n2;
	int s1, s2, tmp;

	cout << "Enter num2 size: ";
	cin >> s2;
	for(int i=0; i<s2; i++) {
		cin >> tmp;
		n2.push_back(tmp);
	}
	cout << "Enter num1 size: ";
	cin >> s1;
	for(int i=0; i<s1; i++) {
		cin >> tmp;
		n1.push_back(tmp);
	}

	cout << "Output: ";
	map<int, int> pos;
	for(int i=0; i<s2; i++) {
		pos[n2[i]] = i;
	}

	for(int i=0; i<s1; i++) {
		int curr = n1[i];
		int nxt = n2[pos[curr]+1];
		for(int j=pos[curr]+1; j < s2; j++ ) {
			if(n2[j] > curr) {
				nxt = n2[j];
				break;
			}
		}
		if(nxt > curr) {
			cout << nxt << " ";
		} else {
			cout << -1 << " ";
		}
	}
}