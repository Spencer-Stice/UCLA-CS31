#include <iostream>
#include <string>
using namespace std;
int sum()
{
	int i;
	cout << "i: ";
	cin >> i;
	int total = 0;
	while (i > 0) {
		total += i % 10;
		i /= 10;
	}
	cout << total << endl;
	return 1;
}