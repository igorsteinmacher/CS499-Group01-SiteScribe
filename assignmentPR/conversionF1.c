// CS499-Group01-SiteScribe
// Pull Request Assignment
// 4th Sept 2018
// Owner: Colton Nunley
// Contributers: Joseph Remy, Julian Bell, and Tanner Massahos

// Required imports
#include <stdio.h>
#include <stdlib.h>

//Defining bools
typedef int bool;
#define true 1
#define false 0

// Method pre-declarations
bool alphaValidate(char input);
bool characteristic(char numString[], int* c);
int charToInt(char* charArray);
bool mantissa(char numString[], int* numerator, int* denominator);


/*___________________________________________________________________________*/
//Validates that the given char is actually a number
bool alphaValidate(char input)
{
    if(input >= '0' && input <= '9')
        {
            return true;
        }
    return false;
}
/*___________________________________________________________________________*/


/*___________________________________________________________________________*/
// Returns the part of a float before the decimal (like a floor function).
bool characteristic(char numString[], int* c)
{
	int index = 0, result;
	char tempArray[100];
	//Iterates to the decimal place, unless theres no mantissa
	while(numString[index] != '.' && numString[index] != '\0')
	{
		tempArray[index] = numString[index]; //Grab the characteristic.
		index++;
	}
	
	result = charToInt(tempArray); //Turn the characteristic into an int.
	if(result != -1) // Makes sure chars are ints. -1 indicates a non-int.
	{
		tempArray[index] = '\0';
		*c = result;
		return true;
	}
	else return false;
}
/*___________________________________________________________________________*/


/*___________________________________________________________________________*/
//Converts character into an integer.
int charToInt(char* charArray)
{
    int finalInt = 0, int index =0; // The return int and iterator

    //Loop through every alhpa numeric char in the string and convert
    //into corresponding int.
    while(charArray[index] != '\0')
    {
    	if(alphaValidate(charArray[index]) == false) //char is not an int
    	{
    		return -1;
    	}

        finalInt = finalInt * 10 + charArray[index] - '0'; // - '0' removes all 0's.

    	index++
    }
  
    // return the final integer that has been converted from the passed string.
    return finalInt;
}
/*___________________________________________________________________________*/


/*___________________________________________________________________________*/
// Returns the part of a float after decimal (significand)
bool mantissa(char numString[], int* numerator, int* denominator)
{
	int index = 0, index2 = 0, result, pow = 1;
	char tempArray[1000];
	
	//This will skip the characteristic and jump to the mantissa. (which is after the '.')
	while(numString[index] != '.') 
	{
		if(numString[index] == '\0') //If there is not mantissa, then return default
		{
			*numerator = 0; //default numerator
			*denominator = pow; //default denomerator
			return true;
		}

		index++;	
	}
	index++; //'jumps over the '.' char

	//In the case there is a Mantissa, grab every char until null terminator
	while (numString[index] != '\0')
	{
		tempArray[index2] = numString[index];
		index2++;
		pow *= 10;
		index++;
	}

	result = charToInt(tempArray);
	if(result != -1) // Makes sure chars are ints. -1 indicates a non-int.
	{
		*numerator = result;
		*denominator = pow; 
		return true;
	}
	else return false;

}
/*___________________________________________________________________________*/


int main()
{
	int c, n, d;
	char number[] = "123.4567";

	//If both functions recieve a valid string
	if(characteristic(number, &c) && mantissa(number, &n, &d))
	{
	    printf("Characteristic: %d\n", c);
	    printf("Mantissa: numerator - %d denominator - %d\n", n, d);
		return true;
	}
	else
	{
	    printf("ERROR: invalid string\n");
	    return false;
	}
}
