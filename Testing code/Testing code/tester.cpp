#include <iostream> <string> <cctype>
using namespace std;
int tester() {
	int n;
	cin >> n;
	for (int candidate = 3; candidate < n; ++candidate) {
		bool isPrime = true;
		for (int x = 2; x < candidate; x++) {
			if (candidate% x == 0) {
				isPrime = false;
			}
		
		}
		if (isPrime) {
			cout << candidate << " ";
		}

	}
	return 1;
}