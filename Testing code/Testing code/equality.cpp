#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool equality(int arr[], int n, int num)
{
	for (int i = n-1; i >=0; i--)
		if (arr[i] != ((num%10)))
			return false;
		else
		{
			num /= 10;
		}
	return true;
}

int maidsjferouihgfiuoeryt9r87e7trkjerhtn()
{
	int sentence[5] = { 1,2,7,4,5 };
	cout << equality(sentence, 5, 12745);
	return 1;
}