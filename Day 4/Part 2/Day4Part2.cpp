#include <iostream>
#include <fstream>
#include <string>
#include <vector> 



using namespace std;

int main() {


	fstream inputfile;
	string sectionassignments;
	int overlap = 0;


	inputfile.open("input.txt", ios::in);
	while (getline(inputfile, sectionassignments)) {
		int commaloc = sectionassignments.find(',');
		string subassignment1 = sectionassignments.substr(0, commaloc);
		string subassignment2 = sectionassignments.substr(commaloc, sectionassignments.length());

		int subassignment1dashloc = subassignment1.find('-');
		int subassignment2dashloc = subassignment2.find('-');

		int subassignment1min = stoi(subassignment1.substr(0, subassignment1dashloc));
		int subassignment2min = stoi(subassignment2.substr(1, subassignment2dashloc - 1));

		int subassignment1max = stoi(subassignment1.substr(subassignment1dashloc + 1, subassignment1.length()));
		int subassignment2max = stoi(subassignment2.substr(subassignment2dashloc + 1, subassignment2.length()));


		if (subassignment1min <= subassignment2min && subassignment1max >= subassignment2min) {
			overlap++;
		}
		else if (subassignment1min <= subassignment2max && subassignment1max >= subassignment2max)
		{
			overlap++;
		}
		else if (subassignment2min <= subassignment1min && subassignment2max >= subassignment1min) {
			overlap++;
		}
		else if (subassignment2min <= subassignment1max && subassignment2max >= subassignment1max)
		{
			overlap++;
		}


	}

	return overlap;

}