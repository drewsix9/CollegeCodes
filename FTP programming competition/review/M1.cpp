#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string &s1, string &s2) {
	if (s1.size() != s2.size())
		return false;

	set<char> count;
	for (char c : s1)
		count.insert(c);
	for (char c : s2)
		count.erase(c);

	return count.empty() == true;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << (isAnagram(s1, s2) ? "YES" : "NO");
}
