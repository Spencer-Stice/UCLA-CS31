#include <iostream>
using namespace std;
int perf()
{
	int n;
	cout << "n: ";
	cin >> n;
	int total = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
			total += i;
	}
	if (total == n)
		cout << "perf";
	else
		cout << "not";
	return 1;
}
