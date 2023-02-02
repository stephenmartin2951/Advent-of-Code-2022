#pragma once
#include <string>
#include <map>
#include <vector>


std::map<std::string, int> directorySize;
std::map<std::string, std::string> childrenDirectories;
std::map<std::string, std::string> parentDirectory;
std::string currentDirectory;
bool listingChildren = false;
int totalSizeSum = 0;
std::vector<std::string> parentTracker;
std::string parentString;