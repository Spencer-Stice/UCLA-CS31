#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;
bool rangeSearch(int sorted_nums[], int n, int target,
	int& start, int& end)
{
	int currentLow = 1000;
	int currentHigh = 0;
	for (int i = 0; i < n; i++)
	{
		if (sorted_nums[i] == target && i <= currentLow)
		{
			currentLow = i;
		}
		if (sorted_nums[i] == target && i >= currentHigh)
		{
			currentHigh = i;
		}
	}
	if (currentLow != 1000)
	{
		start = currentLow;
		end = currentHigh;
		return true;
	}
	else
		return false;
}
int mai5n()
{
	int test[5] = { 1,2,2,3,4 };
	int one = 0;
	int two = 0;
	cout << rangeSearch(test, 5, 5, one, two);
	cout << one << two;
	return 1;
}