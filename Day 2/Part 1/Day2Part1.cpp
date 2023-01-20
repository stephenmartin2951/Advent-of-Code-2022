#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>



using namespace std;

int main() {

	fstream inputFile;

	string roundPlay;
	int myScore = 0;
	enum values{Rock = 1, Paper = 2, Scissors = 3};
	enum outcomes{Win = 6, Draw = 3, Loss = 0};

	inputFile.open("input.txt", ios::in);
	while (getline(inputFile, roundPlay)) {
		char theirPlay = roundPlay[0];
		char myPlay = roundPlay[2];
		if (theirPlay == 'A') {
			switch (myPlay) {
			case 'X':
				myScore += Draw + Rock;
				break;
			case 'Y':
				myScore += Win + Paper;
				break;
			case 'Z':
				myScore += Loss + Scissors;
				break;
			}
		}
		else if (theirPlay == 'B') {
			switch (myPlay) {
			case 'X':
				myScore += Loss + Rock;
				break;
			case 'Y':
				myScore += Draw + Paper;
				break;
			case 'Z':
				myScore += Win + Scissors;
				break;
			}
		}
		else if (theirPlay == 'C') {
			switch (myPlay) {
			case 'X':
				myScore += Win + Rock;
				break;
			case 'Y':
				myScore += Loss + Paper;
				break;
			case 'Z':
				myScore += Draw + Scissors;
				break;
			}
		}
	}

	cout << myScore;
	return myScore;

}