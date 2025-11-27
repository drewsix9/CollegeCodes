#include <iostream>
#include <string>
#include <set>

using namespace std;

set<char> vowels = {'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'};

int main(){
	string str;
	int count = 0;
	cout << "Input:\n";
	getline(cin, str);
	for(char c:str){
		if(vowels.count(c) > 0)
			count++;
	}
	cout << "Output:\n" << count;
}
