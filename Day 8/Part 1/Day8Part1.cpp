#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Day8Part1.h"
using namespace std;

void arrayBuilder()
{
	fstream inputfile("input.txt", ios::in);
	string lineRead;
	int x = 0;
	while (getline(inputfile, lineRead))
	{	
		int y = 0;
		for (auto& number : lineRead)
		{
			treeSizeVec[x][y] = number - 48;
			y++;
		}
		x++;
	}
}

std::vector<int> northBuilder(int x, int y)
{
	std::vector<int> northVec;
	for (int i = 0; i < x; ++i)
	{
		northVec.push_back(treeSizeVec[i][y]);
	}
	return northVec;
}

std::vector<int> southBuilder(int x, int y)
{
	std::vector<int> southVec;
	for (int i = x + 1; i < treeSizeVec.size(); ++i)
	{
		southVec.push_back(treeSizeVec[i][y]);
	}
	return southVec;
}

int main() 
{
	arrayBuilder();
	vector<vector<int>>::iterator row;
	vector<int>::iterator treeInRow;
	int x = 1;
	for (row = treeSizeVec.begin() + 1; row != treeSizeVec.end() - 1; ++row)
	{
		for (treeInRow = row->begin() + 1; treeInRow != row->end() - 1; ++treeInRow)
		{
			int currentTreeHeight = *treeInRow;
			std::vector<int> northVec = northBuilder(x, distance(row->begin(), treeInRow));
			std::vector<int> southVec = southBuilder(x, distance(row->begin(), treeInRow));
			if (all_of(treeInRow + 1, row->end(), [currentTreeHeight](auto& treeheight) {return currentTreeHeight > treeheight; })) { visibleTrees++; }
			else if (all_of(row->begin(), treeInRow, [currentTreeHeight](auto& treeheight) {return currentTreeHeight > treeheight; })) { visibleTrees++; }
			else if (all_of(northVec.begin(), northVec.end(), [currentTreeHeight](auto& treeheight) {return currentTreeHeight > treeheight; })) { visibleTrees++; }
			else if (all_of(southVec.begin(), southVec.end(), [currentTreeHeight](auto& treeheight) {return currentTreeHeight > treeheight; })) { visibleTrees++; }
		}
		x++;
	}

	return visibleTrees + 392;
}