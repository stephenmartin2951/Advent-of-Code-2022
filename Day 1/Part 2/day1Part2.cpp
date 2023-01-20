#include "day1Part2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>



using namespace std;

int main() {

	fstream inputFile;
	int calories = 0;
	int maxCalories = 0;
	int secondMostCalories = 0;
	int thirdMostCalories = 0;


	inputFile.open("input.txt", ios::in);
		string caloriesString;
		while (getline(inputFile, caloriesString)) {
			if (caloriesString.length() > 0) {
				calories += stoi(caloriesString);
			}
			else {
				if (calories >= maxCalories) {
					thirdMostCalories = secondMostCalories;
					secondMostCalories = maxCalories;
					maxCalories = calories;
				}
				else if (calories >= secondMostCalories) {
					thirdMostCalories = secondMostCalories;
					secondMostCalories = calories;
				}
				else if (calories >= thirdMostCalories) {
					thirdMostCalories = calories;
				}
				calories = 0;
			}
		}
		cout << maxCalories + secondMostCalories + thirdMostCalories;
		return maxCalories + secondMostCalories + thirdMostCalories;

}