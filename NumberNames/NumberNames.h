#ifndef NUMBER_NAME_H
#define NUMBER_NAME_H

#include <iostream>
#include <math.h>
using namespace std;

const string WORDS_DIGITS[20] = {
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
	"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};
const string WORDS_TENS[8] = {
	"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

namespace numName
{

	string intName(int num)
	{
		
		string result = "";
		if (num < 0)
		{
			result = "negative ";
			num = -num;
		}
		
		int thou = floor(num / 1000);
		int hund = floor(num / 100 % 10);
		int flat = num % 100;

		if (thou > 0)
		{
			result = intName(thou) + " thousand" + (num - thou * 1000 > 0 ? " " : "");
		}
		if (hund > 0)
		{
			result = result + WORDS_DIGITS[hund] + " hundred" + (flat > 0 ? " and " : "");
		}
		if (flat > 0)
		{
			if (flat < 20)
			{
				result = result + WORDS_DIGITS[flat];
			}
			else
			{
				int tens = floor(flat / 10);
				int units = flat % 10;
				result = result + WORDS_TENS[tens - 2];

				if (units > 0)
				{
					result = result + "-" + WORDS_DIGITS[units];
				}
			}
		}
		return result;

	};
	string floatName(float num)
	{
		string result = "";
		float whole, fractional;
		fractional = modf(num, &whole);
		result = intName(static_cast<int>(whole));
		fractional = fabs(fractional);
		
		if (fractional < 0)
		{
			return result;
		}
		result = result + " point";
		fractional *= 10;
		do 
		{
			result = result + " " + WORDS_DIGITS[static_cast<int>(fractional)];
			fractional = fmod(fractional * 10, 10);
		} while (fractional > 0);
		
		return result;
	};

}

#endif
