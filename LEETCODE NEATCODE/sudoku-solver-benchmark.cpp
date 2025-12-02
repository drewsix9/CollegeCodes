#include <bit>
#include <chrono> // For timing
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <windows.h> // For Sleep function

using namespace std;

class Solution {
public:
  vector<set<char>> mp_rows;
  vector<set<char>> mp_cols;
  map<pair<int, int>, set<char>> mp_grid;
  Solution() {
    mp_rows.resize(9);
    mp_cols.resize(9);
  }
  bool isValid(vector<vector<char>> &board, int i, int j, char tryChar) {
    return (mp_rows[i].count(tryChar) == 0 && mp_cols[j].count(tryChar) == 0 && mp_grid[{i / 3, j / 3}].count(tryChar) == 0);
  }

  void solveSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char curr = board[i][j];
        if (curr == '.')
          continue;
        mp_rows[i].insert(curr);
        mp_cols[j].insert(curr);
        mp_grid[{i / 3, j / 3}].insert(curr);
      }
    }
    solveSudokuRecurse(board);
  }

  bool solveSudokuRecurse(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char curr = board[i][j];
        if (curr != '.')
          continue;
        for (int n = 1; n <= 9; n++) {
          char tryChar = char(n + '0');
          if (isValid(board, i, j, tryChar)) {
            board[i][j] = tryChar;
            mp_rows[i].insert(tryChar);
            mp_cols[j].insert(tryChar);
            mp_grid[{i / 3, j / 3}].insert(tryChar);
            if (solveSudokuRecurse(board)) {
              return true;
            } else {
              board[i][j] = '.';
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

  void printBoard(vector<vector<char>> &board, int highlightRow = -1, int highlightCol = -1) {
    system("cls"); // Clear screen for Windows
    cout << "\n+----------+----------+----------+\n";
    for (int i = 0; i < 9; i++) {
      cout << "| ";
      for (int j = 0; j < 9; j++) {
        if (i == highlightRow && j == highlightCol) {
          cout << "[" << board[i][j] << "]"; // Brackets for current cell
        } else {
          cout << " " << board[i][j] << " ";
        }
        if ((j + 1) % 3 == 0)
          cout << "| ";
      }
      cout << "\n";
      if ((i + 1) % 3 == 0) {
        cout << "+----------+----------+----------+\n";
      }
    }
    Sleep(100); // Delay to visualize (milliseconds)
  }

  bool solveSudokuRecurseVisual(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char curr = board[i][j];
        if (curr != '.')
          continue;
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
              Sleep(50);
              board[i][j] = '.';
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

  void solveSudokuVisual(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char curr = board[i][j];
        if (curr == '.')
          continue;
        mp_rows[i].insert(curr);
        mp_cols[j].insert(curr);
        mp_grid[{i / 3, j / 3}].insert(curr);
      }
    }
    cout << "Starting Sudoku Solver with Visual Backtracking...\n";
    Sleep(1000);
    printBoard(board);
    solveSudokuRecurseVisual(board);
    cout << "\n\n Sudoku Solved!\n";
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

class Solution2 {
  uint16_t rows[9] = {0};
  uint16_t cols[9] = {0};
  uint16_t subgrid[9] = {0};
  vector<pair<int, int>> blanks;
  bool visualMode = false;

public:
  void setup(vector<vector<char>> &board) {
    blanks.reserve(81);
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') {
          blanks.emplace_back(i, j);
        } else {
          set3Cond(i, j, board[i][j] - '1');
        }
      }
    }
  }

  void printBoard(vector<vector<char>> &board, int highlightRow = -1, int highlightCol = -1) {
    system("cls"); // Clear screen for Windows
    cout << "\n+----------+----------+----------+\n";
    for (int i = 0; i < 9; i++) {
      cout << "| ";
      for (int j = 0; j < 9; j++) {
        if (i == highlightRow && j == highlightCol) {
          cout << "[" << board[i][j] << "]"; // Brackets for current cell
        } else {
          cout << " " << board[i][j] << " ";
        }
        if ((j + 1) % 3 == 0)
          cout << "| ";
      }
      cout << "\n";
      if ((i + 1) % 3 == 0) {
        cout << "+----------+----------+----------+\n";
      }
    }
    Sleep(100); // Delay to visualize (milliseconds)
  }

  void set3Cond(int i, int j, int n) {
    const int16_t mask = 1 << n;
    rows[i] |= mask;
    cols[j] |= mask;

    const int16_t gridIndx = (i / 3) * 3 + j / 3;
    subgrid[gridIndx] |= mask;
  }

  bool solve(vector<vector<char>> &board, uint16_t indx) {
    if (indx == blanks.size()) {
      return true;
    }

    auto [i, j] = blanks[indx];
    const int gridIndx = (i / 3) * 3 + j / 3;
    uint16_t notMask = ~(rows[i] | cols[j] | subgrid[gridIndx]) & 0b111111111;
    uint16_t bit = 0;

    for (; notMask; notMask ^= bit) {
      bit = __bit_floor(notMask);
      const int nthBit = __countr_zero(bit);
      char tryChar = '1' + nthBit;

      board[i][j] = tryChar;
      rows[i] |= bit;
      cols[j] |= bit;
      subgrid[gridIndx] |= bit;

      if (visualMode) {
        printBoard(board, i, j);
        cout << "Trying " << tryChar << " at position (" << i << ", " << j << ")\n";
      }

      if (solve(board, indx + 1))
        return true;

      if (visualMode) {
        cout << "Backtracking from (" << i << ", " << j << ")...\n";
        Sleep(50);
      }

      rows[i] ^= bit;
      cols[j] ^= bit;
      subgrid[gridIndx] ^= bit;
      board[i][j] = '.';
    }
    return false;
  }

  void solveSudokuVisual(vector<vector<char>> &board) {
    visualMode = true;
    setup(board);
    cout << "Starting Sudoku Solver (Optimized) with Visual Backtracking...\n";
    Sleep(1000);
    printBoard(board);
    solve(board, 0);
    cout << "\n\n Sudoku Solved!\n";
  }

  void solveSudoku(vector<vector<char>> &board) {
    visualMode = false;
    setup(board);
    solve(board, 0);
  }
};

int main() {
  vector<vector<char>> board(9, vector<char>(9));
  cout << "Enter board:\n";
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> board[i][j];
    }
  }

  cout << "\n========================================\n";
  cout << "SOLUTION 1 (Set-Based Approach)\n";
  cout << "========================================\n";

  // Create a copy of the board for Solution 1
  vector<vector<char>> board1 = board;

  auto start1 = chrono::high_resolution_clock::now();

  Solution sol1;
  sol1.solveSudoku(board1);

  auto end1 = chrono::high_resolution_clock::now();
  auto duration1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1);

  cout << "\nFinal board (Solution 1):\n";
  for (auto &v : board1) {
    for (char &c : v) {
      cout << c;
    }
    cout << endl;
  }
  cout << "\n⏱️ Solution 1 Execution Time: " << duration1.count() << " ms\n";

  cout << "\n========================================\n";
  cout << "SOLUTION 2 (Bitmasking Optimized)\n";
  cout << "========================================\n";

  // Create a copy of the board for Solution 2
  vector<vector<char>> board2 = board;

  auto start2 = chrono::high_resolution_clock::now();

  Solution2 sol2;
  sol2.solveSudoku(board2);

  auto end2 = chrono::high_resolution_clock::now();
  auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);

  cout << "\nFinal board (Solution 2):\n";
  for (auto &v : board2) {
    for (char &c : v) {
      cout << c;
    }
    cout << endl;
  }
  cout << "\nSolution 2 Execution Time: " << duration2.count() << " ms\n";

  cout << "\n========================================\n";
  cout << "PERFORMANCE COMPARISON\n";
  cout << "========================================\n";
  cout << "Solution 1 (Sets):        " << duration1.count() << " ms\n";
  cout << "Solution 2 (Bitmasking):  " << duration2.count() << " ms\n";

  if (duration2.count() < duration1.count()) {
    double speedup = (double)duration1.count() / duration2.count();
    cout << "\nSolution 2 is " << speedup << "x faster!\n";
  } else if (duration1.count() < duration2.count()) {
    double speedup = (double)duration2.count() / duration1.count();
    cout << "\nSolution 1 is " << speedup << "x faster!\n";
  } else {
    cout << "\nBoth solutions took the same time!\n";
  }
  cout << "========================================\n";
}
