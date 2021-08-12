#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;
int ma7jf83hjfedin() {
	char phrase[] = "How the turntables.";
	int n = strlen(phrase);
	for (int i = 0; i < n; i++) { // change in part b
		phrase[strlen(phrase) - 1] = '\0';
	}
	cout << "Result: " << phrase << endl;
	return 1;
}
