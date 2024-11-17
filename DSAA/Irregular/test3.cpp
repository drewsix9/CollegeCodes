#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


int hasConsecutive(string &str) {
	for (size_t i = 0; i < str.size() - 1; i++) {
		if (str[i] == str[i + 1])
			return i;
	}
	return -1;
}

void deleteConsecutive(string &str, int i) {
	if (i == -1) {
		return;
	}
	str.erase(i, 2);
	return;
}

void process(string &str) {
	int i = hasConsecutive(str);
	while (i != -1) {
		deleteConsecutive(str, i);
		i = hasConsecutive(str);
	}
}

int main() {
	string line, word;
	vector<string> input;
	cout << "Enter input:\n";
	while (line.back() != '.') {
		getline(cin, line);
		input.push_back(line);
	}
	cout << "\nOutput:\n";
	for (string s : input) {
		stringstream ss(s);
		while (ss >> word) {
			process(word);
			cout << word << " ";
		}
		cout << endl;
	}
}
