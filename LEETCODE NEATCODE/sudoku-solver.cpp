#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <windows.h>  // For Sleep function

using namespace std;

class Solution {
public:
	vector<set<char>> mp_rows;
	vector<set<char>> mp_cols;
	map<pair<int, int>, set<char >> mp_grid;
	Solution() {
		mp_rows.resize(9);
		mp_cols.resize(9);
	}
	bool isValid(vector<vector<char>>& board, int i, int j, int numTry) {
		char curr = board[i][j];
		return (mp_rows[i].count(curr) == 0 && mp_cols[j].count(curr) == 0 && mp_grid[ {i / 3, j / 3}].count(curr) == 0);
	}

	void solveSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char curr = board[i][j];
				if (curr == '.') continue;
				mp_rows[i].insert(curr);
				mp_cols[j].insert(curr);
				mp_grid[ {i / 3, j / 3}].insert(curr);
			}
		}
		solveSudokuRecurse(board);
	}

	bool solveSudokuRecurse(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char curr = board[i][j];
				if (curr != '.')continue;
				for (int n = 1; n <= 9; n++) {
					if (isValid(board, i, j, n)) {
						board[i][j] = char(n + '0');
						mp_rows[i].insert(curr);
						mp_cols[j].insert(curr);
						mp_grid[ {i / 3, j / 3}].insert(curr);
						if (solveSudokuRecurse(board)) {
							return true;
						} else {
							board[i][j] = '.';
							mp_rows[i].erase(curr);
							mp_cols[j].erase(curr);
							mp_grid[ {i / 3, j / 3}].erase(curr);
						}
					}
				}
				return false;
			}
		}
		return true;
	}

	void printBoard(vector<vector<char>>& board, int highlightRow = -1, int highlightCol = -1) {
		system("cls");  // Clear screen for Windows
		cout << "\n+----------+----------+----------+\n";
		for (int i = 0; i < 9; i++) {
			cout << "| ";
			for (int j = 0; j < 9; j++) {
				if (i == highlightRow && j == highlightCol) {
					cout << "[" << board[i][j] << "]";  // Brackets for current cell
				} else {
					cout << " " << board[i][j] << " ";
				}
				if ((j + 1) % 3 == 0) cout << "| ";
			}
			cout << "\n";
			if ((i + 1) % 3 == 0) {
				cout << "+----------+----------+----------+\n";
			}
		}
		Sleep(100);  // Delay to visualize (milliseconds)
	}

	bool solveSudokuRecurseVisual(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char curr = board[i][j];
				if (curr != '.')continue;
				for (int n = 1; n <= 9; n++) {
					char tryChar = char(n + '0');
					if (mp_rows[i].count(tryChar) == 0 && 
					    mp_cols[j].count(tryChar) == 0 && 
					    mp_grid[{i / 3, j / 3}].count(tryChar) == 0) {
						
						board[i][j] = tryChar;
						mp_rows[i].insert(tryChar);
						mp_cols[j].insert(tryChar);
						mp_grid[{i / 3, j / 3}].insert(tryChar);
						
						printBoard(board, i, j);
						cout << "Trying " << tryChar << " at position (" << i << ", " << j << ")\n";
						
						if (solveSudokuRecurseVisual(board)) {
							return true;
						} else {
					cout << "Backtracking from (" << i << ", " << j << ")...\n";
					Sleep(50);							board[i][j] = '.';
							mp_rows[i].erase(tryChar);
							mp_cols[j].erase(tryChar);
							mp_grid[{i / 3, j / 3}].erase(tryChar);
						}
					}
				}
				return false;
			}
		}
		return true;
	}

	void solveSudokuVisual(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char curr = board[i][j];
				if (curr == '.') continue;
				mp_rows[i].insert(curr);
				mp_cols[j].insert(curr);
				mp_grid[{i / 3, j / 3}].insert(curr);
			}
		}
		cout << "Starting Sudoku Solver with Visual Backtracking...\n";
		Sleep(1000);
		printBoard(board);
		solveSudokuRecurseVisual(board);
		cout << "\n\n✓ Sudoku Solved!\n";
	}

	void printSets() {
		cout << "mp_rows:\n";
		for (int i = 0; i < 9; i++) {
			cout << "Row " << i + 1 << ": ";
			for (auto &c : mp_rows[i]) {
				cout << c << " ";
			}
			cout << endl;
		}
		cout << "\nmp_cols:\n";
		for (int i = 0; i < 9; i++) {
			cout << "Column " << i + 1 << ": ";
			for (auto &c : mp_cols[i]) {
				cout << c << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	Solution sol;
	vector<vector<char>> board(9, vector<char>(9));
	cout << "Enter board:\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
		}
	}
	cout << "Output:\n";
	for (auto &v : board) {
		for (char &c : v) {
			cout << c;
		}
		cout << endl;
	}
	sol.solveSudokuVisual(board);
	
	cout << "\nFinal board:\n";
	for (auto &v : board) {
		for (char &c : v) {
			cout << c;
		}
		cout << endl;
	}
}
