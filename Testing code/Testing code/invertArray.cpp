#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;


void invert(int matrix[][4], int n)
{
	int temp[4][4];
	for (int r = 0; r < n; r++)
		for (int c = 0; c < 4; c++)
			temp[c][r] = matrix[r][c];
	for (int r = 0; r < n; r++)
		for (int c = 0; c < 4; c++)
			matrix[r][c] = temp[r][c];
}




int mai3hfuoihefn() {
	int yes[4][4] = { 1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7 };
	invert(yes, 4);
	for (int r = 0; r < 4; r++)
		for (int c = 0; c < 4; c++)
		{
			cout << yes[r][c];
			if (c == 3)
				cout << endl;
		}
	return 1;
}
