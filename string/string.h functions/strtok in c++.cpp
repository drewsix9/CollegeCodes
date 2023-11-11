#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void StringStreamStyleTokenziation() { // space as Token
  string input;
  getline(cin, input); // fgets() in C

  string token;
  stringstream stream(input);

  while (getline(stream, token, ' ')) {
    cout << token << endl;
  }
}

void StringStreamStyleSpaceTokenziation() { // space as Token
  string input;
  getline(cin, input); // fgets() in C

  string token;
  stringstream stream(input);

  while (stream >> token) {
    cout << token << endl;
  }
}

void CppStyleTokenization() {
  string input;
  getline(cin, input);

  size_t pos = 0;
  string token;
  while ((pos = input.find(' ')) != string::npos) {
    token = input.substr(0, pos);
    cout << token << " ";
    input.erase(0, pos + 1);
  }
}

void CStyleTokenization() {
  char input[100];
  fgets(input, 100, stdin);
  strtok(input, "\n");

  char *token = strtok(input, " ");
  while (token != NULL) {
    printf("%s ", token);
    token = strtok(NULL, " ");
  }
}

int main() {
  StringStreamStyleTokenziation();
}
