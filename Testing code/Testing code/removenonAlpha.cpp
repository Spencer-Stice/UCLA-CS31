#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;
void removenonAlpha(char words[])
{
	for (int i = 0; words[i] != '\0';)
	{
		if (!isalpha(words[i]))
		{
			for (int j = i; ;j++)
			{
				words[j] = words[j + 1];
				if (words[j] == 0)
				{
					break;
				}
			}
		}
		else
			i++;

	}

}


int ma97856786in()
{
	char monkey[] = "S5mal.lb-erg! Is+ C$s Senpai$$$";
	removenonAlpha(monkey);
	cout << monkey;
	return 1;
}
