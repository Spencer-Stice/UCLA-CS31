#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;


void awordShiftLeft(char str[])
{
	int wEnd = 0;
	int wStart;
	int count = 0;
	bool foundEnd = false;
	for (int i = 0; str[i] != '\0' && i < strlen(str);)
	{
		if (str[i] == ' ')
		{
			foundEnd = false;
			int wStart = i + 1;
			for (int j = i + 2; j <= strlen(str); j++)
			{
				if (str[j] == ' ')
				{
					wEnd = j - 1;
					char temp = str[wStart];
					cout << "start: " << wStart << " end: " << wEnd << " temp: " << temp << endl;
					for (int a = wStart; a < wEnd; a++)
					{
						str[a] = str[a + 1];
					}

					cout << strlen(str);
					str[wEnd] = temp;
					cout << str[wEnd];
					cout << endl << str << endl;
					foundEnd = true;
					i += (wEnd - wStart + 3);
					cout << i;
					break;
				}
			}
			cout << " yo " << str[i + 1] << i << wEnd << wStart;

		}


		else if (str[i + 1] == '\0' && str[i] != ' ' && !foundEnd)
		{
			cout << "THIS RAN";
			for (int p = i; p >= 0; p--)
			{
				if (str[p] == ' ')
				{
					char temp = str[p + 1];
					wStart = p + 1;
					cout << " NOW temp: " << temp << " wStart: " << wStart << " wEnd: " << wEnd;
					for (int a = wStart; a < strlen(str)-1; a++)
					{
						str[a] = str[a + 1];
					}
					str[strlen(str) - 1] = temp;
					cout << endl << str << endl << "yes this was me";
					cout << "me ran";
					i = strlen(str);
					break;
				}
				
			}

		}
		else
		{
			i++;
		}

	}
}



int ma83954kjdfh9873ye4fin() 
{
	char test[16] = "I love tes CS31";
	awordShiftLeft(test);
	cout << test << endl; // "I ovel S31C"
	cout << test[5];
	return 1;
}
