#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

int hasRepeated(string &str)
{
	unordered_set<char> c;
	for (int i = 0; i < str.length(); i++)
	{
		c.insert(str[i]);
	}

	if (str.length() == c.size())
	{
		return 0;
	}
	return 1;
}

int main()
{
	string input, token;
	cout << "Enter input: ";
	getline(cin, input);

	string max;
	int maxWord = 0;
	stringstream stream(input);
	while (stream >> token)
	{
		if (hasRepeated(token))
		{
			int count = token.length();
			if (count > maxWord)
			{
				max = token;
				maxWord = count;
			}
		}
	}

	cout << "\nOutput: " << max;

	return 0;
}