#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;
int min()
{
	int stacks;
	cin >> stacks;
	for (int i = 1; i <= stacks; i++)
	{
		for (int j = 1; j <= stacks - i; j++)
			cout << " ";
		for (int k = 1; k <= i; k++)
			cout << "$";
		cout << endl;
	}
	return 1;
}