#include <bits/stdc++.h>
using namespace std;

int main() {
	int size, tmp, num;
	map<int, int> count;
	cout << "Input:\n";
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> tmp;
		count[tmp]++;
	}
	cin >> num;
	cout << "Output:\n";
	cout << count[num];
}
