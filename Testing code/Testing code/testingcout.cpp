#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;
bool ranFirst = false;
string mayberunsFirst()
{
	ranFirst = true;
	return "fhasdi";
}
int maybeRanSecond()
{
	if (ranFirst)
		return 0;
	if (!ranFirst)
		return 1;
}
int mai3452dgfn()
{
	cout << maybeRanSecond() << mayberunsFirst();
	return 1;
}