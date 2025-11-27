#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> neigh = {
	{-1, -1}, {0, -1}, {1, -1},
	{-1, 0}, {1, 0},
	{-1, 1}, {0, 1}, {1, 1}
};

bool inBounds(int r, int c, int row, int col) {
	return row >= 0 && row < r && col >= 0 && col < c;
}

int countNeigh(vector<vector<char>> &vec, int R, int C, int row, int col) {
	int count = 0;
	for (auto [x, y] : neigh) {
		if (!inBounds(R, C, row + x, col + y)) {
			continue;
		}
		if (vec[row + x][col + y] == '*')
			count++;
	}
	return count;
}

void minesweeper(vector<vector<char>> &vec, int &R, int &C) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (vec[i][j] == '*') {
				cout << "* ";
				continue;
			}
			cout << countNeigh(vec, R, C, i, j) << " ";
		}
		cout << endl;
	}
}

int main() {
	int r, c;
	char tmp;
	cin >> r >> c;
	vector<vector<char>> vec;
	for (int i = 0; i < r; i++) {
		vec.push_back(vector<char>());
		for (int j = 0; j < c; j++) {
			cin >> tmp;
			vec[i].push_back(tmp);
		}
	}
	cout << "Output:" << endl;
	minesweeper(vec, r, c);
}
