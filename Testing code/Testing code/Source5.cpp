#include <iostream>
#include <string>
using namespace std;
int mystery(int arr[], int n, int target)
{
	int begin = 0;
	int end = n - 1;
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		if (arr[mid] > target)
			end = mid - 1;
		else if (arr[mid] < target)
			begin = mid + 1;
		else
			return mid;
	}
	return begin;
}

int maipaoghreigrn()
{
	int sentence[5] = {1,2,3,4,5 };
	cout << mystery(sentence, 4, 3);
	cout << endl;
	return 1;
}