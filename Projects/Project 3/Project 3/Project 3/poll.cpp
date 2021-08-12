#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;
//Below is a listing of all of the functions I wrote. I created many so that the code is more readable.
bool isSyntacticallyCorrect(string pollData);
int tallyVotes(string pollData, char party, int& voteTally);
bool isValidForecast(string pollData, int& startLocation);
bool isValidUppercaseStateCode(string stateCode);
bool isValidStateCode(string stateCode);
string extractStateCode(string pollData, int start);
int addVotes(string pollData, char party, bool& zero);

//Does nothing
int main()
{
}

//This function checks if a pollData string is valid before it is passed to the tallyVotes function
bool isSyntacticallyCorrect(string pollData)
{
    bool ans = true;
    int i = 0;
	while(i< pollData.size())
	{
        if (!isdigit(pollData.at(i)))                   //If the first character in the forecast is not a digit, return false
        {
            ans = false;
            i = pollData.size();
        }
        else if (!isValidForecast(pollData, i))         //Given a digit character, determine if next characters constitute a valid forecast by calling
            {                                           // isValidForecast with the current index
                ans = false;
                i = pollData.size();                    //If the next few characters do not form a valid forecast according to isValidForecast, return false;
            }
	}
    return ans;
}

//This function takes in a pollData string, party character, and voteTally integer and acts according to the spec
int tallyVotes(string pollData, char party, int& voteTally)
{
    int mightAdd = 0;
    bool isZero = false;
    if (!isSyntacticallyCorrect(pollData))              //If the string is not a valid pollData string according to isSyntacticallyCorrect, return 1;
        return 1;
    if (!isalpha(party))                                //If the party character is not a letter, return 2;
        return 2;
    mightAdd = addVotes(pollData, party, isZero);       //If there are no issues so far, tally the votes for a certain party and store the result in mightAdd using
    if (isZero)                                         // addVotes
        return 3;                                       //If any of the forecasts include 0 votes, return 3 because isZero was set to true by addVotes
    voteTally = mightAdd;                               //If everything checks out, set voteTally and return 0;
    return 0;
}

//Determines if a sequence of characters is a valid forecast given the whole string and a starting location
bool isValidForecast(string pollData, int& startLocation)
{
    bool ans = false;
    if (pollData.size() - 1 < startLocation + 3)        //If the remaining portion of the pollData string is too short to be a forecast, return false;
        return false;
    if (isdigit(pollData.at(startLocation)))
    {
        if (isdigit(pollData.at(startLocation + 1)) || isalpha(pollData.at(startLocation + 1)))
        {

            if (isdigit(pollData.at(startLocation + 1)))
            {

                if (isalpha(pollData.at(startLocation + 2)) && (pollData.size()-1 >= startLocation + 4))

                {

                    if (isValidStateCode(extractStateCode(pollData, startLocation + 2)))
                    {

                        if (isalpha(pollData.at(startLocation + 4)))        //If there are two digits followed by a valid state code followed by a letter, it is a valid forecast
                        {
                            ans = true;
                            startLocation = startLocation + 5;              //Move the index five forward so that isSyntactically correct moves on to the next sequence

                        }
                    }
                }
            }
            else if (isalpha(pollData.at(startLocation + 1)))
            {

                if (isValidStateCode(extractStateCode(pollData, startLocation + 1)))
                {

                    if (isalpha(pollData.at(startLocation + 3)))            //If there is one digit followed by a valid state code followed by a letter, it is a valid forecast
                    {
                        {
                            ans = true;
                            startLocation = startLocation + 4;                  //Move the index four forward so that isSyntactically correct moves on to the next sequence
                        }
                    }
                }
            }
        }
    }
    return ans;
}

//Checks if a proposed state code is valid
bool isValidStateCode(string stateCode)
{
    string s = "";
    for (int j = 0; j < 2; j++)
        s += toupper(stateCode.at(j));                  //Takes a two letter state code and preprocesses it to be capital so that isValidUpperCaseStateCode can work
    return(isValidUppercaseStateCode(s));               //After preprocessing, if the state code is valid according to isValidUpperCaseStateCode, returns true
}

//Checks if a proposed state code is a valid upper case state code (in my case, after the state code has been preprocessed to be capital)
bool isValidUppercaseStateCode(string stateCode)
{
    const string codes =
        "AL.AK.AZ.AR.CA.CO.CT.DE.DC.FL.GA.HI.ID.IL.IN.IA.KS."
        "KY.LA.ME.MD.MA.MI.MN.MO.MS.MT.NE.NV.NH.NJ.NM.NY.NC."
        "ND.OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
    return (stateCode.size() == 2 &&
        stateCode.find('.') == string::npos &&  // no '.' in stateCode
        codes.find(stateCode) != string::npos);  // match found

}

//Takes a pollData string and a starting point and extracts a two letter state code (or if not two letters, isValidUpperCaseStateCode will return false)
string extractStateCode(string pollData, int start)
{
    string ans1 = "";
    string ans2 = "";
    for (int i = start; i < start + 3; i++)
    {
        ans1 += pollData.at(i);                 //Creates a state code based on the starting character and the next character
    }
    return ans1;
}

//Takes a pollData string, party character, and a boolean to test if any forecasts are zero and totals the vote for the given party
int addVotes(string pollData, char party, bool& zero)
{
    int addVotes = 0;
    int ones = 0;
    int tens = 0;
    for (int i = 0; i < pollData.size();)
    {
        if (isdigit(pollData.at(i)))
        {
            if (((pollData.size() - 1 >= i + 4)) && (isdigit(pollData.at(i + 1)) && (toupper(pollData.at(i + 4)) == toupper(party))))
            {
                tens = pollData.at(i) - '0';
                ones = pollData.at(i + 1) - '0';                           //If a forecast with two digit votes is found for the right party, turn the digit characters into ints by
                if (ones == 0 && tens == 0)
                    zero = true;                                          //subtracting '0'. Then, multiply the first one by ten, add the second, and add the result to the total
                
                addVotes = addVotes + (tens * 10) + ones;
                i += 5;                                                     //Move to the next forecast since this one was 5 characters long
            }
            else if (((pollData.size() - 1 >= i + 4)) && (isdigit(pollData.at(i + 1))))
            {

                
                tens = pollData.at(i) - '0';
                ones = pollData.at(i + 1) - '0';
                if (ones == 0 && tens == 0)
                    zero = true;
                i += 5;                                                         //subtracting '0'. Then, multiply the first one by ten, add the second, and add the result to the total
                
            }                                                                   //If the forecast if 5 digits but wrong party, move to the next forecast
            else if (toupper(pollData.at(i + 3)) == toupper(party))
            {
                ones = pollData.at(i) - '0';
                if (ones == 0)                                              //If a forecast with a one digit vote is found for the right party, follow the same process as before
                    zero = true;                                            //but with only one digit
                addVotes += ones;
                i += 4;                                                      //Move to the next forecast since this one was 4 characters long
            }  
            else if (toupper(pollData.at(i + 3)))
            {
                
                ones = pollData.at(i) - '0';
                if (ones == 0)                                              //If a forecast with a one digit vote is found for the right party, follow the same process as before
                    zero = true;
                i += 4;
            }                                                               //If the forecast if 4 digits but wrong party, move to the next forecast
        }
        ones = 0;
        tens = 0;                                                           //Reset the place values
    }
    return addVotes;                                                        //Return the total votes
}