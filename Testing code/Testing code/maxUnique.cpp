#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int maxUnique(int candies[], int k)
{
	int numberUnique = 0;
	int uniqueList[100];
	for (int i = 0; i < k; i++)
	{
		bool isSolo = true;
		for (int j = 0; j < k; j++)
			if (i != j && candies[i] == candies[j])
			{
				isSolo = false;
			}
		if (isSolo)
		{
			numberUnique++;
			uniqueList[i] = candies[i];
		}
	}

	bool isUnique = true;
	for (int i = 0; i < k; i++)
	{
		bool isUnique = true;
		for (int j = 0; j < 50; j++)
			if (candies[i] == uniqueList[j])
			{
				isUnique = false;
			}
		if (isUnique)
		{
			numberUnique++;
			uniqueList[numberUnique] = candies[i];
		}
	}
	if(numberUnique >= k/2)
		return k/2;
	else
	{
		return numberUnique;
	}

}

int m7d8fdkf8ewain()
{
	int sentence[13] = { 9,1,2,7,4,5,5,5, 5, 5,5 ,8, 9 };
	cout << maxUnique(sentence, 13);
	return 1;
}