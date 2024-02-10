
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Stack {
private:
  vector<int> stk;
  int size;

public:
  Stack() {
    stk = {};
    cout << "\nEnter stack size: ";
    cin >> size;
  }

  bool isEmpty() {
    return (stk.empty());
  }

  bool isFull() {
    return (stk.size() == size);
  }

  void push(char input) {
    stk.insert(stk.begin(), input);
    cout << "\nSuccessfully pushed back!" << input;
    displayStack();
  }

  void pop() {
    if (isEmpty()) {
      cout << "\nNothing to pop...";
      return;
    }
    stk.erase(stk.begin());
    cout << "\nSuccessfully popped top!";
    displayStack();
  }

  void displayStack() {
    cout << "\n     top";
    cout << "\n       |";
    cout << "\n       v";
    cout << "\nStack: ";
    for (int n : stk) {
      cout << n << " ";
    }
  }

  void reverseStack() {
    reverse(stk.begin(), stk.end());
    cout << "\nSuccessfully reversed!";
    displayStack();
  }

  void printTop() {
    cout << "\nTop: ";
    cout << stk.back();
  }

  int &top() {
    return stk.back();
  }

  void clear() {
    if (isEmpty()) {
      cout << "\nNothing to clear...";
      return;
    }
    stk.clear();
    cout << "\nSuccessfully cleared stack!";
  }
};

int main() {
  Stack stack1;

  int num, choice = -1;

  while (1) {
    cout << "\n\n0 - Exit";
    cout << "\n1 - Push";
    cout << "\n2 - Pop";
    cout << "\n3 - Display";
    cout << "\n4 - Reverse";
    cout << "\n5 - Clear";
    cout << "\nEnter choice: ";
    cin >> choice;

    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (stack1.isFull()) {
        cout << "\n[INFO] Stack is Full!";
        break;
      }
      cout << "\nEnter num: ";
      cin >> num;
      stack1.push(num);
      break;
    case 2:
      stack1.pop();
      break;
    case 3:
      stack1.displayStack();
      break;
    case 4:
      stack1.reverseStack();
      break;
    case 5:
      stack1.clear();
      break;
    default:
      cout << "\nInvalid input...\n\n";
    }
  }
  return 0;
}

// int main() {
//   Stack stk;
//   map<char, char> m = {
//       {']', '['},
//       {')', '('},
//       {'}', '{'},
//   };

//   string test = "{[]}";

//   for (char c : test) {
//     if (m.find(c) != m.end()) {
//       if (stk.isEmpty()) {
//         cout << "\nNOT Balanced Parentheses! Leading Closing Bracket";
//         return 0;
//       }
//       if (stk.top() != m[c]) {
//         cout << "\nNOT Balanced Parentheses!";
//         return 0;
//       }
//       stk.pop();
//     } else {
//       stk.push(c);
//     }
//   }

// stk.displayStack();

// if (stk.isEmpty()) {
//   cout << "\nBalanced Parentheses!";
// } else {
//   cout << "\nNOT Balanced Parentheses!";
// }
// }