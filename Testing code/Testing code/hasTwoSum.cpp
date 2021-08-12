#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool hasTwoSum(int arr[], int n, int sum)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (j != i && arr[j] + arr[i] == sum)
				return true;
	return false;
}

int makljderhtoierh9t84ykj5hrer3978in()
{
	int sentence[5] = { 1,2,7,4,5 };
	cout << hasTwoSum(sentence, 5, 2);
	return 1;
}