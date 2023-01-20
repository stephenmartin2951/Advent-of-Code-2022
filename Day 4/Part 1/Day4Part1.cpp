#include <iostream>
#include <fstream>
#include <string>
#include <vector> 



using namespace std;

int main() {

	fstream inputFile;
	string sectionAssignments;
	int fullyContained = 0;


	inputFile.open("input.txt", ios::in);
	while (getline(inputFile, sectionAssignments)) {
		int commaLoc = sectionAssignments.find(',');
		string subAssignment1 = sectionAssignments.substr(0, commaLoc);
		string subAssignment2 = sectionAssignments.substr(commaLoc, sectionAssignments.length());

		int subAssignment1DashLoc = subAssignment1.find('-');
		int subAssignment2DashLoc = subAssignment2.find('-');

		int subAssignment1Min = stoi(subAssignment1.substr(0, subAssignment1DashLoc));
		int subAssignment2Min = stoi(subAssignment2.substr(0 + 1, subAssignment2DashLoc - 1));

		int subAssignment1Max = stoi(subAssignment1.substr(subAssignment1DashLoc + 1, subAssignment1.length()));
		int subAssignment2Max = stoi(subAssignment2.substr(subAssignment2DashLoc + 1, subAssignment2.length()));
		
		if (subAssignment1Min <= subAssignment2Min && subAssignment1Max >= subAssignment2Max) {
			fullyContained++;
		} else if (subAssignment2Min <= subAssignment1Min && subAssignment2Max >= subAssignment1Max) {
			fullyContained++;
		}


	}

	cout << fullyContained;
	return fullyContained;

}