#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << "Input:\n";
	string buffer, str;
	getline(cin, buffer);
	stringstream ss(buffer);
	map<string, int> count;
	while (ss >> str) {
		count[str]++;
	}
	cout << "Output:\n";
	for (auto [k, v] : count) {
		cout << k << " " << v << endl;
	}

	vector<pair<string, int>> vec(count.begin(), count.end());
	sort(vec.begin(), vec.end(), [] (const auto &a, const auto &b) {
		return a.second > b.second;
	});
	
	cout << "\nSorted:\n";
	for (auto [k,v] : vec){
		cout << k << " " << v << endl;
	}
}
