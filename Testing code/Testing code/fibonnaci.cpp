#include <iostream>
#include <cmath>
using namespace std;
int fib()
{
	int n;
	cout << "n: ";
	cin >> n;
	if (n < 1) {
		cout << "error";
		return 1;
	}
	int one = 0;
	int two = 1;
	int three = 0;
	int term = 2;
	int temp = 0;
	do {
		three = one + two;
		temp = two;
		two = three;
		one = temp;
		term++;
	} while (term < n);
	cout << three;
	return 1;
}