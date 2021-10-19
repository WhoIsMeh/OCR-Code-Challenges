#ifndef ASCII_TABLE_H
#define ASCII_TABLE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

namespace tablegen
{

	// generates ASCII Table using a 2D vector of strings, optional whitespace
	std::string ASCIITable(
		std::vector<std::vector<std::string>> mainVector,
		int spacing = 1 // default value of 1
	) {
		std::string result;
		std::vector<int> columnWidth; // later used for ensuring spacing is consistent through columns
		std::string hrline = "+"; // we will always have a connecting point at the start and end of each horizontal line
		for (int i = 0; i < mainVector[0].size(); i++) // iterate over columns, assuming each row has the same number of cells
		{
			columnWidth.push_back(0); // basic starting point - no width should be less than 0
			for (std::vector<std::string> row : mainVector) // find the largest element in the column, and store it in columnWidth
			{
				columnWidth[i] = (std::max(
					(int)row[i].size(),
					columnWidth[i]
				));
			}
			hrline += std::string(columnWidth[i] + (spacing * 2), '-') + "+"; // add horizontal lines for each character in the row, with '+' to represent intersections

		}
		result += "\n" + hrline + "\n"; // horizontal line to represent the top-most edge of the table
		for (std::vector<std::string> row : mainVector) // find each row in the 2D vector
		{
			result += "|"; // left-most edge of the table
			for (int i = 0; i < row.size(); i++) // unable to use (std::string cell : row) here due to us needing to know the iterator
			{
				float space = (columnWidth[i] + spacing * 2) - row[i].size(); // spacing on both sides + existing column width = total cell width
				result += (std::string((int)floor(space / 2), ' ') // adding padding to each cell to ensure consistent column sizes
					+ row[i]
					+ std::string((int)ceil(space / 2), ' ')
					+ "|");
			}
			result += "\n" + hrline + "\n"; // add a horizontal line with newline chars at each end to separate rows into a table
		}
		return result;
	}

}

#endif
