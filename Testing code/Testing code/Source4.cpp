#include <iostream>
#include <string>
using namespace std;
string reverseIT(string original) {
	string reversed = "";
	string rWord = "";
	int lastSpace = 0;
	int nextSpace = 0;
	for (int i = 0; i < original.size(); i++)
	{

		if (original.at(i) == ' ' || i == original.size()-1)
		{
			rWord = "";
			lastSpace = nextSpace;
			nextSpace = i;
			for (int j = nextSpace-1; j >= lastSpace; j--)
			{
				rWord += original.at(j);
			}

			reversed += (rWord + " ");
		}
	}

	return reversed;
}

int safgdasfadsin() {
	string s;
	getline(cin, s);
	cout << reverseIT(s);
	return 1;
}