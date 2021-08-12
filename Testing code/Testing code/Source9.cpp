#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;
void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;

}


int ma4563in()
{
	int x = 5;
	int y = 0;
	swap(x,y);
	cout << x << y;
	return 1;
}
