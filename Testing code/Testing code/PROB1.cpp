#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;
int mn()
{
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size() - 2; i++)
	{
		if (isdigit(s.at(i)) && isupper(s.at(i + 1)))
		{
			cout << s.at(i) << endl;
		}
	}
	return 1;
}