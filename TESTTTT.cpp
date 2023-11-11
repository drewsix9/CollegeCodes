#include <iostream>
#include <string>

int main()
{
	std::string str = "hello world";
	std::string reversed_str(str.rbegin(), str.rend());
	std::cout << reversed_str << std::endl; // prints "dlrow olleh"
	return 0;
}