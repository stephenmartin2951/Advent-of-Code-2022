#include "day1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

int main() {

	fstream inputFile;
	int calories = 0;
	int maxCalories = 0;

	inputFile.open("input.txt", ios::in);
	if (inputFile.is_open()) {
		string caloriesString;
		while (getline(inputFile, caloriesString)) {
			if (caloriesString.length() > 0) {
				calories += stoi(caloriesString);
			}
			else {
				maxCalories = max(maxCalories, calories);
				calories = 0;
			}
			
		}
		cout << maxCalories;
		return maxCalories;
	}

}





