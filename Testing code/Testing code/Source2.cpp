#include <iostream>
#include <string>
using namespace std;
int in()
{
	string s;
	getline(cin, s);
	string sback = "";
	for (int i = s.size() - 1; i >= 0; i--)
		sback+=(s.at(i));
	if (sback == s)
		cout << 1;
	else
		cout << 0;
	return 1;
}