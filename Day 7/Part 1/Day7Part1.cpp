#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include "Day7Part1.h"

using namespace std;

vector<string> split(string const& input)
{
	istringstream buffer(input);
	vector<string> ret{ istream_iterator<string>(buffer), {} };

	return ret;
}

void directoryBuilder(map<string, int>& directorySize, map<string, string>& childrenDirectories, map<string, string>& parentDirectory,
	const string &lineRead, bool &listingChildren, string &currentDirectory)
{
	vector<string> splitLine = split(lineRead);



	if (splitLine[0] == "$")
	{
		listingChildren = false;
		if (splitLine[1] == "ls")
		{
			listingChildren = true;
			return;
		}
		else
		{
			if (splitLine[2] == "..")
			{
				string tempDirectory = parentString;
				int toRemove = parentString.find("." + currentDirectory);
				parentString.erase(toRemove, ("." + currentDirectory).length());
				parentString = parentDirectory.at(tempDirectory);
				parentTracker.pop_back();
				currentDirectory = parentTracker.back();
			}
			else
			{
				currentDirectory = splitLine[2];
				parentTracker.push_back(currentDirectory);
				parentString.clear();

				for (auto const& x : parentTracker)
				{
					parentString += "." + x;
				}
			}
		}
	}

	if (listingChildren)
	{
		if (splitLine[0] == "dir")
		{
			if (childrenDirectories.count(parentString))
			{
				string currentVal = childrenDirectories.at(parentString);
				childrenDirectories[parentString] = currentVal + " " + parentString + "." + splitLine[1];
			} 
			else
			{
				childrenDirectories[parentString] = parentString + "." + splitLine[1];
			}
			parentDirectory[parentString + "." + splitLine[1]] = parentString;
		}
		else
		{
			if (directorySize.count(parentString))
			{
				int currentVal = directorySize.at(parentString);
				directorySize[parentString] = currentVal += stoi(splitLine[0]);
			}
			else
			{
				directorySize[parentString] = stoi(splitLine[0]);
			}
		}
	}
}

int finalDirectorySize(const string& key)
{
	int tempSize = 0;

	if (childrenDirectories.count(key))
	{
		vector<string> childrenDirectoriesVector = split(childrenDirectories.at(key));
		for (auto const& y : childrenDirectoriesVector)
		{
			tempSize += finalDirectorySize(y);
		}
	}
	
	if(directorySize.count(key))
		tempSize += directorySize.at(key);

	return tempSize;
}

int main() {

	fstream inputfile;
	string lineRead;	

	inputfile.open("input.txt", ios::in);
	while (getline(inputfile, lineRead)) 
	{
		directoryBuilder(directorySize, childrenDirectories, parentDirectory, lineRead, listingChildren, currentDirectory);
	}

	for (auto const& x : childrenDirectories)
	{
		int finalSize = finalDirectorySize(x.first);
		directorySize[x.first] = finalSize;
	}

	for (auto const& x : directorySize)
	{
		if (x.second <= 100000)
			totalSizeSum += x.second;
	}

	return totalSizeSum;
}