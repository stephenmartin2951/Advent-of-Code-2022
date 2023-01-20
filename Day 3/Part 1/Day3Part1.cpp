#include <iostream>
#include <fstream>
#include <string>
#include <vector> 



using namespace std;

int main() {

	fstream inputFile;

	string rucksack;
	int prioritySum = 0;
	vector<char> charVector{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
							'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

	inputFile.open("input.txt", ios::in);
	while (getline(inputFile, rucksack)) {
		string firstCompartment = rucksack.substr(0, (rucksack.length() / 2));
		string secondCompartment = rucksack.substr(rucksack.length() / 2, rucksack.length() - 1);
		char sharedItem = ' ';

		for (int x = 0; x < firstCompartment.length(); x++) {
			for (int i = 0; i < secondCompartment.length(); i++) {
				if (firstCompartment[x] == secondCompartment[i]) {
					sharedItem = firstCompartment[x];
					break;
				}
			}
		}

		for (int i = 0; i < charVector.size(); i++) {
			if (charVector[i] == sharedItem) {
				prioritySum += i + 1;
				break;
			}
		}
		
	}

	cout << prioritySum;
	return prioritySum;

}