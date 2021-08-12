#include <iostream>
using namespace std;
int maidsfaswe87dfn()
{
	int n;
	cout << "n: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
			if(i != n)
				cout << i << ",";
			else
				cout << i << "";
	}
	return 1;
}
