#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;
int findDuplicate(int A[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (A[i] == A[j] && i != j)
				return A[i];
	return 0;

}
int mai6543gn()
{
	int test[7] = { 1,0,2,3,4,6,4 };
	cout << findDuplicate(test, 7);
	return 1;
}