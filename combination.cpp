#include <bits/stdc++.h>
using namespace std;

void dfs(int n, vector<string>&res, int indx, string& path) {
	if (n == indx) {
		res.emplace_back(path);
		return;
	}
	string ab = "ab";
	for (char c : ab) {
		path.push_back(c);
		dfs(n, res, indx + 1, path);
		path.pop_back();
	}
}

vector<string> combi(int n) {
	vector<string> res;
	string path;
	dfs(n, res, 0, path);
	return res;
}

int main() {
	int n;
	cout << "Enter n: ";
	cin >> n;
	vector<string> res = combi(n);
	sort(res.begin(), res.end());
	cout << "\nOutput: ";
	for (string &s : res) {
		cout << s << " ";
	}
}
