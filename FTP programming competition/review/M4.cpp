#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, c;
	cin >> r >> c;
	vector<vector<int>> vec(r, vector<int>(c, 0));
	for (int i = 0; i < r; i ++) {
		for (int j = 0; j < c; j++) {
			cin >> vec[i][j];
		}
	}
	cout << "\nOutput:\n";
	for (auto v : vec) {
		int sum = 0;
		for (int n : v) {
			sum += n;
		}
		cout << sum << endl;
	}
}
