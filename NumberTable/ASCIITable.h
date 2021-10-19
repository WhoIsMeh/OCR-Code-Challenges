#ifndef ASCII_TABLE_H
#define ASCII_TABLE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

namespace tablegen
{

	std::string ASCIITable(
		std::vector<std::vector<std::string>> vector,
		int spacing = 1
	) {
		std::string result;
		std::vector<int> columnWidth;
		std::string hrline = "+";
		for (int i; i < vector[0].size(); i++)
			{
				columnWidth.push_back(0);
				for (std::vector v: vector)
					{
						columnWidth[i] = (std::max(
							(int) v[i].size(),
							columnWidth[i]
							));
					}
				hrline += (std::string(columnWidth[i] + (spacing * 2), '-') 
					+ ((i != vector[0].size() - 1) ? "+": ""));

			}
		hrline += "+";
		result += "\n" + hrline + "\n";
		for (std::vector<std::string> row: vector)
			{
				for(int i; i < row.size(); i++)
					{
						std::cout << columnWidth[i] << ": ";
						float space = (columnWidth[i] + spacing * 2) - row[i].size();
						std::cout << space << std::endl;
						if (i != row.size() - 1)
							{
								result += (std::string((int) floor(space / 2), ' ') 
									+ row[i]
									+ std::string((int) ceil(space / 2), ' ')
									+ "|");
							}
						else
							{
								result += (std::string((int) floor(space / 2), ' ') 
									+ row[i]);
							}
					}
				result += "\n" + hrline + "\n";
			}
		return result;
	}

}

int main()
{
	std::vector<std::vector<std::string>> v = {
	{"a", "b", "c", "d"},
	{"aaaa", "bbbbbb", "cc", "d"},
	{"aa", "bbb", "ccccc", "dddd"}
	};
	std::cout << tablegen::ASCIITable(v, 1);
	return 0;
}

#endif
