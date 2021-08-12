#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;
bool tripleSum(int A[], int n, int target)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (A[i] + A[j] + A[k] == target && i != j && i != k && k != j)
					return true;
	return 0;

}
int mai8kasfhgiuden()
{
	int test[7] = { 1,0,2,3,4,6,4 };
	cout << tripleSum(test, 7, 9);
	return 1;

}