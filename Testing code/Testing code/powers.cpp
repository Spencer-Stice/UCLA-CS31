#include <iostream>
#include <cmath>
using namespace std;
int mpoers()
{
	int n;
	cout << "n: ";
	cin >> n;
	int a = 0;
	for (int i = 1; ; i++)
	{
		if ((pow(2, i) <= n) && ((pow(2, i + 1) > n)))
		{
			a = i;
				break;
		}
	}
	if (a != 0)
		cout << "num: " << a;
	else {
		cout << "error";
		return 1;
	}
	return 1;
}
