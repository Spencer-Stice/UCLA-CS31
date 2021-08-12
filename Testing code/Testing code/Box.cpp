#include <iostream>
using namespace std;
int maj489ygf9r8ygin()
{
	int n;
	cout << "n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j > i) {
				cout << ".";
			}
			else {
				cout << i + j;
			}
			
		}
		cout << "\n";
	}
	return 1;
}