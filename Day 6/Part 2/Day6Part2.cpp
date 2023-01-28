#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <set>

using namespace std;

int main() {

	fstream inputfile;
	string lineRead;
	const int problemSize = 14;
	vector<char> charVec = {};
	int counter = 0;
	inputfile.open("input.txt", ios::in);
	while (getline(inputfile, lineRead)) {
		for (char& ch : lineRead)
		{
			charVec.insert(charVec.begin(), ch);
			counter++;
			if (charVec.size() == problemSize)
			{
				set<char> dupCheck(charVec.begin(), charVec.end());
				if (dupCheck.size() == charVec.size())
				{
					cout << counter;
					return counter;
				}
				charVec.pop_back();
			}
		}
	}
	return 0;
}