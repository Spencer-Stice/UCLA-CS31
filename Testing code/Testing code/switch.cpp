#include <iostream>
using namespace std;
void mystery(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int m6() {
	int x = 24;
	int y = 107;
	swap(x, y);
	cout << "The value of x is " << x << endl;
	cout << "The value of y is " << y << endl;
	return 1;
}