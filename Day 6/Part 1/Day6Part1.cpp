#include <iostream>
#include <fstream>
#include <string>
#include <vector> 



using namespace std;




int main() {

	fstream inputfile;
	string lineRead;
	const int problemSize = 4;
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
				int matchCount = 0;
				for (int i = 0; i < problemSize; i++)
				{
					if (charVec[i] == charVec[0]) matchCount++;
					if (charVec[i] == charVec[1]) matchCount++;
					if (charVec[i] == charVec[2]) matchCount++;
					if (charVec[i] == charVec[3]) matchCount++;	
				}
				if (matchCount == 4) {
					cout << counter;
					return counter;
				}
				charVec.pop_back();
			}
		}
	}
	return 0;
}