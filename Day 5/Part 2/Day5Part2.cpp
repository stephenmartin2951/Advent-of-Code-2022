#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <stack>
#include <math.h>



using namespace std;

void supplyStackBuilder(vector<stack<char>>& supplyStacks, string& lineRead)
{
	for (int i = 0; i < lineRead.length(); i++)
	{
		char letter = lineRead[i];
		if (isalpha(letter))
		{
			int supplyStackNum = floor(i / 4.f);
			supplyStacks[supplyStackNum].push(letter);
		}
	}
}

void crateMover(vector<stack<char>>& supplyStacks, string& lineRead)
{
	int numMoved = stoi(lineRead.substr(5, 7));
	int moveFromStack = stoi(lineRead.substr(12, 13)) - 1;
	int moveToStack = stoi(lineRead.substr(lineRead.length() - 1)) - 1;
	vector<char> crateHolder(numMoved);

	for (int i = 0; i < numMoved; i++)
	{
		char crateMoved = supplyStacks[moveFromStack].top();
		supplyStacks[moveFromStack].pop();
		crateHolder.push_back(crateMoved);
	}

	for (int i = 0; i < numMoved; i++)
	{
		supplyStacks[moveToStack].push(crateHolder.back());
		crateHolder.pop_back();
	}

	
}

void stackReversal(vector<stack<char>>& supplyStacks)
{
	for (int i = 0; i < 9; i++)
	{
		char item;
		stack<char> tempStack;
		while (!supplyStacks[i].empty())
		{
			item = supplyStacks[i].top();
			supplyStacks[i].pop();
			tempStack.push(item);
		}
		supplyStacks[i] = tempStack;
	}
}


int main() {

	fstream inputfile;
	string lineRead;
	vector<stack<char>> supplyStacks(9);
	bool buildingStacks = true;
	bool movingCrates = false;


	inputfile.open("input.txt", ios::in);
	while (getline(inputfile, lineRead)) {

		if (movingCrates)
		{
			crateMover(supplyStacks, lineRead);
		}

		if (lineRead.length() == 0)
		{
			buildingStacks = false;
			movingCrates = true;
			stackReversal(supplyStacks);
		}

		if (buildingStacks)
		{
			supplyStackBuilder(supplyStacks, lineRead);
		}

	}

	for (int i = 0; i < 9; i++)
	{
		cout << supplyStacks[i].top();
	}

	return 0;

}