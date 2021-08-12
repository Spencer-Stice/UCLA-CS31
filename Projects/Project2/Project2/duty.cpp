#include <iostream>
#include <string>
using namespace std;
int main()
{						
	cout << "Cheese type: ";
	string cheeseType;
	getline(cin, cheeseType);		//get cheese type from input

	if (cheeseType == "")			//check to see if the user entered a valid input
	{
		cout << "---" << endl;
		cout << "You must enter a cheese type" << endl;
		return 1;
	}
	
	double cheeseValue;
	cout << "Value: ";
	cin >> cheeseValue;				//get the value of the cheese from input
	cin.ignore(10000, '\n');		//ignore the newline entered by the user so that the user is able to enter a cheese importer for the next input

	if (cheeseValue <= 0)			//check to see if the user entered a positive value for the cheese
	{
		cout << "---" << endl;
		cout << "The value must be positive" << endl;
		return 1;
	}

	cout << "Importer: ";
	string cheeseImporter;
	getline(cin, cheeseImporter);
			
	if (cheeseImporter == "")		//check to see if the user entered a valid cheese importer
	{
		cout << "---" << endl;
		cout << "You must enter an importer" << endl;
		return 1;
	}

	double lowDuty = 0.011;			//establishes the amounts of the duties in case the value changes later
	double mediumDuty = 0.02;
	double specialDuty = 0.014;
	double highDuty = 0.029;
	cout.setf(ios::fixed);			//set the precision of cout doubles to reflect USD
	cout.precision(2);
	cout << "---" << endl;			//as long as the input is valid, always print --- before the final line

	if (cheeseValue <= 1000)		//the following if and else if statements determine the value of the duty based on the value of the cheese being imported and the name of the cheese
	{
		cout << "The import duty for " << cheeseImporter << " is $" << cheeseValue * lowDuty << endl;		//if the value is less than 10000, the duty is simply 1.1% of the value
	}
	else if (cheeseValue <= 13000 && (cheeseType != "cheshire" && cheeseType != "stilton"))		//if the cheese value is greater than 1000 and less then 13000, a different duty is calculated (by determining the amount to be taxed higher via subtraction
	{
		cout << "The import duty for " << cheeseImporter << " is $" << (1000 * lowDuty) + ((cheeseValue - 1000) * mediumDuty) << endl;
	}
	else if (cheeseValue <= 13000 && (cheeseType == "cheshire" || cheeseType == "stilton"))		//if the cheese type is cheshire or stilton, impose a special duty
	{
		cout << "The import duty for " << cheeseImporter << " is $" << (1000 * lowDuty) + ((cheeseValue - 1000) * specialDuty) << endl;
	}
	else if (cheeseValue > 13000 && (cheeseType == "cheshire" || cheeseType == "stilton"))							//if the cheese is valued greater than 13000 and the cheese type is special, apply appropiate duties
	{
		cout << "The import duty for " << cheeseImporter << " is $" << (1000 * lowDuty) + ((12000) * specialDuty) + ((cheeseValue - 13000)* highDuty) << endl;
	}
	else if (cheeseValue > 13000 && (cheeseType != "cheshire" && cheeseType != "stilton"))							//if the cheese is valued greater than 13000 and the cheese type is not special, apply appropiate duties
	{
		cout << "The import duty for " << cheeseImporter << " is $" << (1000 * lowDuty) + ((12000) * mediumDuty) + ((cheeseValue - 13000) * highDuty) << endl;
	}
}