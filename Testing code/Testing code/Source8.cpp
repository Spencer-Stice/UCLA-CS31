#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;


void wordShiftLeft(char str[]) {
	int len = strlen(str);
	int beginWord = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') {
			char beginChar = str[beginWord];
			for (int j = beginWord; j < i - 1; j++) {
				str[j] = str[j + 1];
			}
			str[i - 1] = beginChar;
			beginWord = i + 1;
		}
	}
	if (beginWord < len) {
		char beginChar = str[beginWord];
		for(int j = beginWord; j<len-1;j++)
		{
		str[j] = str[j+1];}
		str[len-1]=beginChar;
	}
}



int m6f78ds96fain()
{
	char test[] = "I love CS31";
	wordShiftLeft(test);
	cout << test << endl; // "I ovel S31C"
	char testr[] = "I.love.CS31";
	wordShiftLeft(testr);
	cout << testr << endl; // ".love.CS31I"
	return 1;
}
