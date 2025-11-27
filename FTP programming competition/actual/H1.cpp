#include <bits/stdc++.h>
using namespace std;

bool validate(vector<vector<char>> &arr) {
	vector<set<char>> set_rows(9, set<char>());
	vector<set<char>> set_cols(9, set<char>());
	map<pair<int, int>, set<char>> set_grid; // r/3 c/3

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char curr = arr[i][j];
			if (curr == '.')
				continue;
			if (set_rows[i].count(curr) > 0 || set_cols[j].count(curr) > 0 || set_grid[ {i / 3, j / 3}].count(curr) > 0) {
				return false;
			}
			set_rows[i].insert(curr);
			set_cols[j].insert(curr);
			set_grid[ {i / 3, j / 3}].insert(curr);
		}
	}
	return true;
}

int main() {
	cout << "Enter board:\n";
	vector<vector<char>> arr(9, vector<char>(9, '.'));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}
	cout << "\nOutput: ";
	cout << boolalpha << validate(arr);
}
