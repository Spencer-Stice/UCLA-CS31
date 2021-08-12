#include <iostream>
#include <string>
using namespace std;

//appends value to the end of n elements
int appendToAll(string a[], int n, string value)
{
	if (n < 0)											//return -1 if n is negative
		return -1;
	else
	{
		for (int i = 0; i < n; i++)
			a[i] += value;								//loop through the n elements and append value to the end
	}
	return n;
}

//searches the array for a target string and returns the index of the target, if applicable
int lookup(const string a[], int n, string target)
{
	if (n <= 0)											//return -1 if n is negative
		return -1;
	else
	{
		for (int i = 0; i < n; i++)						//loop through the n elements and check to see if the element is the target, if so, returning the index
			if (a[i] == target)
				return i;
	}
	return -1;											//if target is not found, return -1
}

//returns the index of the maximum string
int positionOfMax(const string a[], int n)
{
	if (n <= 0)											//return -1 if n is negative
		return -1;
	else
	{
		string currentMax = a[0];						//sets the first value as the current maximum
		int currentMaxIndex = 0;
		for (int i = 1; i < n; i++)
			if (a[i] > currentMax)
			{
				currentMaxIndex = i;					//loops through the array and if any elements are greater than the current max,
				currentMax = a[i];						//change the value of the current max and the index of the current max
			}
		return currentMaxIndex;
	}
}

//takes the element at pos, moves it to the end of the array, and shifts elements left (no addiitonal array created)
int rotateLeft(string a[], int n, int pos)
{
	if (n < 0)											//return -1 if n is negative
		return -1;
	else if (pos > n - 1)								//if the function will search for a value greater than the length of the array, return -1
		return -1;
	else if (pos < 0)
		return -1;
	else
	{
		string toBeMoved = a[pos];						//store the string at pos into a temporary string
		for (int i = pos; i < n - 1; i++)
			a[i] = a[i + 1];							//shift elements left starting at pos by assigning the element at the next index into
		a[n - 1] = toBeMoved;							//the element at the current index
		return pos;
	}
}

//returns the number of consecutive "runs" in an array
int countRuns(const string a[], int n)
{
	if (n < 0)											//return -1 if n is negative
		return -1;
	else if (n == 0)									//return 0 if there are no elements and therefore no runs
		return 0;
	else
	{
		int runs = 1;									//start with 0 runs
		string currentRun = a[0];						//set the current run to the first value in the array
		for (int i = 0; i < n; i++)
			if (a[i] != currentRun)						//loop through the array and if the current value is not equal to the current run,
			{											//increase runs by one and set the new current run
				runs++;
				currentRun = a[i];
			}									
		return runs;									//return the number of "runs"
	}
}

//reverses the order of the array (no additional arrays created)
int flip(string a[], int n)
{
	if (n < 0)											//return -1 if n is negative
		return -1;
	else
	{
		int repeatTimes = n / 2;						//loop through half of the array, if the number of elements is odd, repeat until
		for (int i = 0; i < repeatTimes; i++)			//the program has looped through all elements that are "paired", leaving one in the middle
		{	
			string temp = a[i];							//flip the values of the elements using a temporary string:
			a[i] = a[n - 1 - i];						//after storing the value at the current index into a temp string, store the "paired"
			a[n - 1 - i] = temp;						//element into the current one, then store the temp string into the "paired" value
		}
		return n;
	}
}

//returns the index of the first elements that do not match, with additional rules as specified in the spec
int differ(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0)								//all of these checks return values without checking the actual string elements, if possible
		return -1;
	else if (n1 == 0 && n2 >0)
		return 0;
	else if (n1 > 0 && n2 == 0)
		return 0;
	else if (n1== 0 && n2 == 0)
		return 0;
	else
	{
		int term;
		int ans = 0;
		if (n1 > n2)
			term = n2;
		else
			term = n1;									//loop through until the program reaches the end of the shorter array
		for (int i = 0; i < term; i++)
			if (a1[i] != a2[i])							//if the two elements in the arrays do not match, return the index of these elements
				return i;
			else if (i == term - 1)
				ans = i;								//if all elements match, return the length of the shorter array
		return ans + 1;
	}
}

//checks if one array is a subsequence of another
int subsequence(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0)								//all of these checks return values without checking the actual string elements, if possible
		return -1;
	else if (n2 == 0)
		return 0;
	else if (n1 == 0)
		return -1;
	else
	{
		bool inIt = true;
		int startIndex = -1;
		string startIndicator = a2[0];					//set the "start indicator" as the first element of the second array so that the program knows
		for (int i = 0; i < n1;i++)						//what to search for
		{	
			startIndex = -1;
			if (a1[i] == startIndicator)				//loop through the first array until it arrives at the start indicator
			{
				startIndex = i;							//set the start index to the index where the start indicator is located
			}
			if (startIndex != -1 && (n1-1 >= startIndex+n2-1))	//if the second array is long enough for the subsequence to still be in it
			{
				for (int j = 0; j < n2; j++)
				{
					if (a1[j + startIndex] != a2[j])	//starting at the "start index" loop through both arrays to see if they match
						inIt = false;					//if ANY of the elements do not match, set the boolean inIt to false
					if (j == n2 - 1 && inIt)			//if the program reaches the end of the subsequence array and the arrays match (inIt is true)
					{
						return startIndex;
					}
				}
			}
		}
			return -1;
	}
}

//returns the index of the first element in the first array that matches ANY of the elements in the second array
int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0)								//all of these checks return values without checking the actual string elements, if possible
		return -1;
	else if (n1 == 0 || n2 == 0)
		return -1;
	else
	{
		for (int i = 0; i < n1; i++)					//loop through each element in the main array
			for (int j = 0; j < n2; j++)				//for each element in the main array, loop through the elements of the second array
				if (a1[i] == a2[j])						//if the value of the element in the first array equals any of the second array's elements
					return i;		
	}
	return -1;
}

//sorts the array so that all elements less than divider are before divider and elements greater than divider are after divider, returns the index of the first element >= divider (no additional array created)
int divide(string a[], int n, string divider)
{
	if (n < 0)											//if n is negative, return -1
		return -1;
	else
	{
		string temp;
		int returnIndex = -1;
		int testIndex = -1;
		int numLessThanIndex = 0;
		for (int i = 0; i < n; i++)
			if (a[i] < divider)							//loop through the array to determine how many elements should go before divider
				numLessThanIndex++;
		int lastSmallerIndex = numLessThanIndex - 1;
		for (int i = 0; i < n;)							//loop through all elements of the array with no specific condition for incrementation
		{
			if (a[i] > divider && i <=lastSmallerIndex)	//if an element that is greater than divider is in the wrong place
			{
				temp = a[i];							//store the current element in a temp string, then shift all elements left and append the element to the end
				for (int j = i; j < n - 1; j++)
					a[j] = a[j + 1];
				a[n - 1] = temp;
				for(int k = 0; k < n; k++)				//this segment of code is repeated and this will be the only one commented(lines 212 to 224):
					if (a[k] >= divider)				//loop through the array to find the first element that is >= divider, store this index
					{
						testIndex = k;
						break;
					}
				for (int k = 0; k < n; k++)				//loop through the array and if all elements are in a valid spot, return testIndex
					if (k<testIndex && a[k]>divider)
						break;
					else if (k > testIndex && a[k] < divider)
						break;
					else if (k == n - 1)
						return testIndex;
			}											//remain at this index if the original value was in the wrong place
			else if(a[i] < divider && i > lastSmallerIndex)
			{
				temp = a[i];							//if an element that is less than divider is in the wrong place
				for (int j = i; j > 0; j--) {
					a[j] = a[j - 1];
				}
				a[0] = temp;							//store the current element in a temp string, then shift all elements right and append the element to the beginning
				for (int k = 0; k < n; k++)
					if (a[k] >= divider)
					{
						testIndex = k;
						break;
					}
				for (int k = 0; k < n; k++)
					if (k<testIndex && a[k]>divider)
						break;
					else if (k > testIndex && a[k] < divider)
						break;
					else if (k == n - 1)
						return testIndex;				//remain at this index if the original value was in the wrong place
			}
			else										//if the current element is not in the wrong place, check to see if the array is correct
			{
				for (int k = 0; k < n; k++)
					if (a[k] >= divider)
					{
						testIndex = k;
						break;
					}
				for (int k = 0; k < n; k++)
					if (k<testIndex && a[k]>divider)
						break;
					else if (k > testIndex && a[k] < divider)
						break;
					else if (k == n - 1)
						return testIndex;
				i++;									//if the array is still incorrect, move on the the next index
			}
		}
		for (int i = 0; i < n; i++)						//find the index of the first element that is >= divider, if possible
			if (a[i] >= divider)
				return returnIndex;
		return n;

	}
}


int main()
{
}