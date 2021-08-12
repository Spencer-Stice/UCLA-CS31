#include <iostream>
using namespace std;
int reverse(int n) {
	int ans = 0;
	while (n > 0)
	{
		int test = n;
		int nLength = 0;
		for (int i = 1; test > 0; i++)
		{
			if (n % 10 > 0)
				nLength++;
			test /= 10;
		}
		int counter = 1;
		int nextNum = n % 10;
		ans += (nextNum* pow(10, nLength));
		n /= 10;
	}
	return ans/10;
}
int mhfdjksahgf() {
	int in;
	cin >> in;
	cout << reverse(in);
	return 1;
}