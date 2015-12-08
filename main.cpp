// This is to overcome an issue that clang++ has with the cstdio header
//void gets();
//void gets() { } 
 
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

static void print_with_spaces(string const & text)
{
	for(char c : text)
	{
		cout << c << ' ';
	}
	cout << endl;
}

int main()
{
	string some_text = "Hello, World!";
	print_with_spaces(some_text);

	return 0;
}

