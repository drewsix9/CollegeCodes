#include <bits/stdc++.h>

#include <windows.h> // For Sleep function

using namespace std;

class Solution {
  set<int> cols;
  set<int> posDiag; // (r+c)
  set<int> negDiag; // (r-c)
  vector<vector<string>> res;
  void printBoard(const vector<string> &board, int highlightRow = -1, int highlightCol = -1) {
    system("cls"); // For Windows, use "clear" for Linux/Mac
    int n = board.size();
    cout << "\n";
    for (int i = 0; i < n; i++) {
      cout << "| ";
      for (int j = 0; j < n; j++) {
        if (i == highlightRow && j == highlightCol) {
          cout << "[" << board[i][j] << "] ";
        } else {
          cout << " " << board[i][j] << "  ";
        }
      }
      cout << "|\n";
    }
    cout << endl;
    Sleep(150); // Visual delay
  }

public:
  // Visual version
  void recurseSolveNQueensVisual(int r, int n, vector<string> &board) {
    if (r == n) {
      vector<string> cpy = vector<string>(board);
      res.emplace_back(cpy);
      cout << "\nSolution found!\n";
      printBoard(board);
      Sleep(500);
      return;
    }

    for (int c = 0; c < n; c++) {
      if (cols.count(c) > 0 || posDiag.count(r + c) || negDiag.count(r - c))
        continue;

      cols.insert(c);
      posDiag.insert(r + c);
      negDiag.insert(r - c);
      board[r][c] = 'Q';

      printBoard(board, r, c);
      cout << "Placed Q at (" << r << ", " << c << ")\n";

      recurseSolveNQueensVisual(r + 1, n, board);

      cout << "Backtracking from (" << r << ", " << c << ")\n";
      board[r][c] = '.';
      printBoard(board, r, c);
      cols.erase(c);
      posDiag.erase(r + c);
      negDiag.erase(r - c);
      Sleep(100);
    }
  }

  // Non-visual, pure backtracking version
  void recurseSolveNQueens(int r, int n, vector<string> &board) {
    if (r == n) {
      res.emplace_back(board);
      return;
    }
    for (int c = 0; c < n; c++) {
      if (cols.count(c) > 0 || posDiag.count(r + c) || negDiag.count(r - c))
        continue;
      cols.insert(c);
      posDiag.insert(r + c);
      negDiag.insert(r - c);
      board[r][c] = 'Q';
      recurseSolveNQueens(r + 1, n, board);
      board[r][c] = '.';
      cols.erase(c);
      posDiag.erase(r + c);
      negDiag.erase(r - c);
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    recurseSolveNQueens(0, n, board);
    return res;
  }
};

void printBoardVisual(const vector<string> &board) {
  int n = board.size();
  cout << "\n+";
  for (int i = 0; i < n; ++i)
    cout << "---+";
  cout << "\n";
  for (int i = 0; i < n; ++i) {
    cout << "| ";
    for (int j = 0; j < n; ++j) {
      cout << board[i][j] << " | ";
    }
    cout << "\n+";
    for (int k = 0; k < n; ++k)
      cout << "---+";
    cout << "\n";
  }
}

void printAllSolutions(const vector<vector<string>> &solutions) {
  cout << "\n================ ALL N-QUEENS SOLUTIONS ================\n";
  int idx = 1;
  for (const auto &sol : solutions) {
    cout << "Solution #" << idx++ << ":\n";
    printBoardVisual(sol);
    cout << "-----------------------------\n";
  }
  cout << "Total solutions: " << solutions.size() << "\n";
}

int main() {
  int n;
  cout << "Enter N for N-Queens: ";
  cin >> n;
  Solution solver;
  auto solutions = solver.solveNQueens(n);
  printAllSolutions(solutions);
  return 0;
}
