#ifndef ASCII_TABLE_H
#define ASCII_TABLE_H

#include <iostream>
#include <vector>
#include <algorithm>

namespace tablegen
{

	std::string ASCIITable(
		std::vector<std::vector<std::string>> vector,
		int spacing = 1
	) {
		std::string result;
		std::string space = std::string(spacing, ' ');
		std::vector<unsigned int> columnWidth;
		for (int i; i < vector[1].size(); i++)
			{
				for (std::vector v: vector)
					{
						columnWidth[i] = std::max(
							(unsigned int) v[i].size() + spacing * 2,
							columnWidth[i]
							);
					}
			}
		for (std::vector<std::string> row: vector)
			{
				for(std::string cell: row)
					{
						result += space + cell.append(space);
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
