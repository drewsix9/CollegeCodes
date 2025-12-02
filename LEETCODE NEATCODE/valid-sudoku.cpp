#include <bits/stdc++.h>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
	vector<set<char>> hash_rows(9, set<char>());
	vector<set<char>> hash_cols(9, set<char>());
	map<pair<int, int>, set<char> > hash_grid;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char curr = board[i][j];
			if (curr == '.')
				continue;
			if (hash_rows[i].count(curr) > 0 || hash_cols[j].count(curr) > 0 || hash_grid[ {i / 3, j / 3}].count(curr) > 0)
				return false;
			hash_rows[i].insert(curr);
			hash_cols[j].insert(curr);
			hash_grid[ {i / 3, j / 3}].insert(curr);
		}
	}
	return true;
}

int main() {
	vector<vector<char>> board(9, vector<char>(9));
	cout << "Enter board:\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
		}
	}
	cout << "Output: " << boolalpha << isValidSudoku(board);
}
