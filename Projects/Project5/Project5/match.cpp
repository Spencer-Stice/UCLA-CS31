#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
#include <cassert>
#include <string>
using namespace std;
const int MAX_WORD_LENGTH = 20;

bool inDoc(char docu[], const char word[])																	//given two c strings, checks to see if the second is a substring of the first
{
	bool done = false;
	int docuLen = strlen(docu);
	for (int c = 0; docu[c] != '\0'; c++)
	{
		if (docu[c] == word[0] && !done && (c == 0 || docu[c - 1] == ' '))
		{
			bool foundMatch = true;
			for (int j = 0; word[j] != '\0'; j++)
			{
				if (docu[c + j] != word[j])
					foundMatch = false;
				if ((c+j+1 == docuLen || docu[c+j+1] == ' ') && foundMatch)
				{																									//returns true if it finds a matching word
					return true;
					done = true;
				}
			}
		}
	}
	return false;
}
int cleanupRules(char wordin[][MAX_WORD_LENGTH + 1], char wordout[][MAX_WORD_LENGTH + 1], int nRules)				//given two, two dimensional c string arrays and the number of rules, cleans up the rules according to the spec
{
	for (int r = 0; r < nRules; r++)
	{
		for (int c = 0; wordin[r][c] != '\0'; c++) {
			if (isalpha(wordin[r][c]))
			{
				wordin[r][c] = tolower(wordin[r][c]);																//makes all letters lowercase
			}
		}

	}
	for (int r = 0; r < nRules; r++)
	{
		for (int c = 0; wordout[r][c] != '\0'; c++) {
			if (isalpha(wordout[r][c]))																			//makes all letters lowercase
				wordout[r][c] = tolower(wordout[r][c]);
		}

	}
	int currentNumClean = 0;
	for (int r = 0; r < nRules; r++)																			//finds all rules where the words match and sets the word in to 9
	{
		if (!strcmp(wordin[r], wordout[r]))
			strcpy(wordin[r], "9");
	}
	for (int r = 0; r < nRules; r++)																			//finds all in words that included non-letters and sets them to 9
	{
			for (int c = 0; wordin[r][c] != '\0'; c++)
			{
				if (!isalpha(wordin[r][c]))
				{
					strcpy(wordin[r], "9");
				}

			}
	}

	for (int r = 0; r < nRules; r++)																			//finds all out words that included non-letters and sets them to the empty string
	{
			for (int c = 0; wordout[r][c] != '\0'; c++)
			{
				if (!isalpha(wordout[r][c]))
				{
					strcpy(wordout[r], "9");
				}

			}
	}
	for (int r = 0; r < nRules; r++)																		//finds all empty string in words and sets them to 9
	{
		if (strcmp(wordin[r], "") == 0)
			strcpy(wordin[r], "9");
	}


	for (int r = 0; r < nRules;)																			//finds all rules where at least one word is 9 and shifts all rules up one to take its place
	{
		if (!strcmp(wordout[r], "9") || !strcmp(wordin[r], "9"))
		{
			for (int d = r; d < nRules - 1; d++)
			{
				strcpy(wordin[d], wordin[d + 1]);
				strcpy(wordout[d], wordout[d + 1]);

			}
			strcpy(wordin[nRules - 1], "8");																//instead of adding the removed rule to the end, appends 8 for each word in its place
			strcpy(wordout[nRules - 1], "8");
		}
		else
			r++;
	}
	for (int r = 0; r < nRules; r++)																		//sums the total current number of clean rules based on how many rules don't contain a word that is 8
	{
		if (strcmp(wordin[r], "8") != 0)
			currentNumClean++;
	}
	for (int r = 0; r < currentNumClean; r++)																//finds all valid in words that duplicates of another rule's in words and sets the words of the duplicate rules to 7
	{
		if (strcmp(wordin[r], "8") != 0 && strcmp(wordout[r], "") == 0)
		{
			for (int d = 0; d < currentNumClean; d++)
			{
				if (strcmp(wordin[r], wordin[d]) == 0 && r != d)
				{
					strcpy(wordin[d], "7");
					strcpy(wordout[d], "7");
				}
			}
		}
	}
	for (int r = 0; r < nRules; r++)																			//finds rules that are not valid (i.e. have a word that has been set to a number) and sets them all to 9 for uniformity
	{
		for (int c = 0; wordin[r][c] != '\0'; c++)
		{
			if (!isalpha(wordin[r][c]))
			{
				strcpy(wordin[r], "9");
				strcpy(wordout[r], "9");
			}

		}
	}
	for (int r = 0; r < nRules;)																			//takes all rules that have been set to 7 or 9 (i.e. all invalid rules) and shifts the valid rules up to take their place, appending 8's for in and out words of these invalid rules
	{																										//onto the end of the array, for uniformity
		if (!strcmp(wordout[r], "9") || !strcmp(wordin[r], "9"))
		{
			for (int d = r; d < nRules - 1; d++)
			{
				strcpy(wordin[d], wordin[d + 1]);
				strcpy(wordout[d], wordout[d + 1]);

			}
			strcpy(wordin[nRules - 1], "8");
			strcpy(wordout[nRules - 1], "8");
		}
		else
			r++;
	}
	currentNumClean = 0;
	for (int r = 0; r < nRules; r++)
	{																										//takes another count of the current number of clean rules by checking which rules have a word that is 8 (set previously)
		if (strcmp(wordin[r], "8") != 0)
			currentNumClean++;

	}
	for (int r = 0; r < currentNumClean; r++)
	{
		if (strcmp(wordin[r], "8") != 0 && strcmp(wordout[r], "") != 0)
		{																									//finds all duplicate two word rules and sets the duplicates' words to 7
			for (int d = 0; d < currentNumClean; d++)
			{
				if ((strcmp(wordin[r], wordin[d]) == 0 && r != d) && (strcmp(wordout[r], wordout[d]) == 0 && r != d))
				{
					strcpy(wordin[d], "7");
					strcpy(wordout[d], "7");
				}
			}
		}
	}
	for (int r = 0; r < nRules; r++)																			//finds all the rules that have been set to a number and changes that number to 9 for uniformity
	{
		for (int c = 0; wordin[r][c] != '\0'; c++)
		{
			if (!isalpha(wordin[r][c]))
			{
				strcpy(wordin[r], "9");
				strcpy(wordout[r], "9");
			}

		}
	}
	for (int r = 0; r < nRules;)																			//finds all the rules that have been set to a number and shifts other rules up to take their place and appends a 8 on the end of the array for uniformity
	{
		if (!strcmp(wordout[r], "9") || !strcmp(wordin[r], "9"))
		{
			for (int d = r; d < nRules - 1; d++)
			{
				strcpy(wordin[d], wordin[d + 1]);
				strcpy(wordout[d], wordout[d + 1]);

			}
			strcpy(wordin[nRules - 1], "8");
			strcpy(wordout[nRules - 1], "8");
		}
		else
			r++;
	}
	currentNumClean = 0;																					//now that all invalid rules have been set to 8, counts and returns the number of rules that have no words that are 8 (all valid remaining rules), which are
	for (int r = 0; r < nRules; r++)																		//already at the beginning of the array
	{
		if (strcmp(wordin[r], "8") != 0)
			currentNumClean++;

	}
	return currentNumClean;
}

int determineScore(const char document[], const char wordin[][MAX_WORD_LENGTH + 1], const char wordout[][MAX_WORD_LENGTH + 1], int nRules)
{
	char mDocument[251] = "";
	int currentChars = 0;
	int docScore = 0;
	for (int i = 0; document[i] != '\0'; i++)															//takes the given document and converts it to an equivalent form with all lowercase characters and no punction or extra spaces
	{
		if (isalpha(document[i]))
		{
			mDocument[currentChars] = tolower(document[i]);
			currentChars++;
		}
		else if (document[i] == ' ')
		{
			
			if (i != 0 && currentChars != 0 && mDocument[currentChars - 1] != ' ')
			{
				mDocument[currentChars] = document[i];
				currentChars++;
			}
		}
	}
	mDocument[currentChars] = '\0';//adds a null character to the end of the modified document to signify it is complete
	for (int r = 0; r < nRules; r++)
	{
		char winStart = wordin[r][0];
		bool alreadyAdded = false;																		//for each rule, check if the modified document will score points based on that rule
		for (int d = 0; mDocument[d] != '\0';d++)
		{
			if (mDocument[d] == winStart && !alreadyAdded)
			{
				if (strcmp(wordout[r], "") == 0)
				{
					if (inDoc(mDocument, wordin[r]))
					{
						docScore++;																		//call inDoc to help determnine if the document should earn a point
						alreadyAdded = true;															//since the document has already earned a point, change this boolean so that even if the document matches the rule in more than one way, it doesn't earn more points
					}
				}
				else
				{
					if (inDoc(mDocument,wordin[r]))
					{
						if (!inDoc(mDocument, wordout[r]) )
						{
//call inDoc to help determnine if the document should earn a point
							docScore++;																	//since the document has already earned a point, change this boolean so that even if the document matches the rule in more than one way, it doesn't earn more points
							alreadyAdded = true;
						}
					}
				}
			}
		}
	}

	return docScore;
}
int main()
{
	char one[] = { "hippos are cute" };
	char two[][21] = { "hippos","are","cute" };
	char three[][21] = { "no","",""};
	cout << "score: " << determineScore(one, two, three, 3);
}