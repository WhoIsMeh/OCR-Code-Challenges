#include <math.h>
using namespace std;

string wordsDigits[20] = {
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
	"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};
string wordsTens[8] = {
	"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

string numberName(int num)
{

	int thou = floor(num / 1000);
	int hund = floor(num / 100 % 10);
	int flat = num % 100;

	string result = "";
	if (thou > 0)
	{
		result = numberName(thou) + " thousand" + (num - thou * 1000 > 0 ? " " : "");
	}
	if (hund > 0)
	{
		result = result + wordsDigits[hund] + " hundred" + (flat > 0 ? " and " : "");
	}
	if (flat > 0)
	{
		if (flat < 20) 
		{
			result = result + wordsDigits[flat];
		}
		else
		{
			int tens = floor(flat / 10);
			int units = flat % 10;
			result = result + wordsTens[tens - 2];

			if (units > 0)
			{
				result = result + "-" + wordsDigits[units];
			}
		}
	}
	return result;

};
