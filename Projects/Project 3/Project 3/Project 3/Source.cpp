#include <iostream>
#include <string>
using namespace std;
int changed(int& j);
int mn()
{
	int j;
	cin >> j;
	changed(j);
	cout << j << endl;

	return 1;
}
int changed(int& a)
{
	a += 5;
	return 0;


}