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
			}
		for (std::vector<std::string> row: vector)
			{
				for(int i; i < row.size(); i++)
					{
						std::cout << columnWidth[i] << ": ";
						float space = (columnWidth[i] + spacing * 2) - vector[i].size();
						std::cout << space << std::endl;
						result += (std::string(' ', (int) floor(space / 2)) 
							+ row[i] 
							+ std::string(' ', (int) ceil(space / 2))
							+ "|");
					}
			}
		return result;
	}

}

int main()
{
	std::vector<std::vector<std::string>> v = {
	{"hi", "bye", "your", "mom"},
	{"dumb", "words", "to", "test"},
	{"ew", "you", "are", "c++17?"}
	};
	std::cout << tablegen::ASCIITable(v, 1);
	return 0;
}

#endif
