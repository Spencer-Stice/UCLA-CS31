#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;


bool charInsert(char str[], int n, int ind, char c)
{
	if (strlen(str) + 2 > n)
	{
		cout << "ran1" << strlen(str) << n;
		return false;
	}
	if (ind > strlen(str))
	{
		cout << "ran32";
		return false;
	}
	for (int i = strlen(str) - 1; i >= ind; i--)
		str[i + 1] = str[i];
	str[strlen(str)] = '\0';
	str[ind] = c;
	return true;
}



int main89898989() {
	char success[10] = "aaaaa";
	bool res = charInsert(success, 10, 1, 'b'); // res should equal true
	cout << res;
	cout << success << endl; // abaaaa\
	char success[10] = "aaaaa";
	char succes[10] = "aaaaa";
	bool reso = charInsert(succes, 10, 5, 'b'); // res should equal true
	cout << succes << endl; // aaaaab
	char failure[6] = "aaaaa";
	bool resr = charInsert(failure, 6, 1, 'b'); // res should equal false
	cout << failure << endl; // aaaaa
	return 1;
}
