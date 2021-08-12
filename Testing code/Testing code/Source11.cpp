#include <iostream>
using namespace std;

void checkTheorem(int nums[], int n)
{
	int times = 0;
	int currentNum;
	for (int i = 0; i < n; i++)
		nums[i] = i + 1;
	for (int i = 0; i < n; i++)
	{
		currentNum = nums[i];
		times = 0;
		while (currentNum != 1 && times < 1000)
		{
			if (currentNum % 2 == 0)
				currentNum /= 2;
			else
				currentNum = currentNum * 3+1;
			times++;
		}
		if (times == 1000)
			cout << nums[i] << endl;
	}
}


int mrain()
{
	int test[10000];
	checkTheorem(test, 10000);
	return 1;
}