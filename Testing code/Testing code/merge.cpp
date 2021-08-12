#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;
void merge(int arr1[], int n1, int arr2[], int n2, int arr3[])
{
	int i1 = 0; int i2 = 0; int i3 = 0;
	while (i3 < n1 + n2 && i1 < n1 && i2 < n2)
	{
		if (arr1[i1] < arr2[i2])
		{
			arr3[i3] = arr1[i1];
			i1++;
			i3++;
		}
		else if (arr1[i1] > arr2[i2])
		{
			arr3[i3] = arr2[i2];
			i2++;
			i3++;
		}
		else
		{
			arr3[i3] = arr1[i1];
			i3++;
			i1++;
		}
	}
	if (i3 != n1 + n2 - 1)
	{
		for (; i1 < n1; i1++)
		{
			arr3[i3] = arr1[i1];
			i3++;
		}
		for (; i2 < n2; i2++)
		{
			arr3[i3] = arr2[i2];
			i3++;
		}
	}
}


int m37590345ain()
{
	char red[] = "1234567891123456";
	char two[16] = "second ";
	char mo[] = "copydontdfoifgherouwihgre";
	int yolo[] = { 1,2,3,4 };
	int yolo2[] = { 1,3,4,5,6 };
	int output[100];
	merge(yolo, 4, yolo2, 5, output);
	for (int i = 0; i < 9; i++)
		cout << output[i];
	int seven = '7';
	seven = seven - '0';
	cout << seven + 1;
	return 1;
}
