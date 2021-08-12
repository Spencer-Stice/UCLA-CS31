#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;
void zeroLeft(int binarry[], int n)
{
	int numZeros = 0;
	int numOnes = 0;
	for (int i = 0; i < n - 1; i++)
		if (binarry[i] == 0)
			numZeros++;
		else if (binarry[i] == 1)
			numOnes++;
	for (int i = 0; i < numZeros; i++)
		binarry[i] = 0;
	for (int i = numZeros; i <= numZeros+numOnes; i++)
		binarry[i] = 1;

}
int maihfe9yr9p843yp3yt9p843yt984ygp9834yg98p4n()
{
	int test[5] = { 1,0,1,0,1 };
	zeroLeft(test, 5);
	for (int i = 0; i < 5; i++)
		cout <<test[i]<<" ";
	return 1;
}