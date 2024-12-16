#pragma once
#include <map>
bool inVec(int x, std::vector<int> vec) {
	for (auto i : vec) {
		if (i == x)
			return true;
	}
	return false;
}
double min(std::map<int, double> koko, std::vector<int> repeat) {
	double minimum=DBL_MAX;
	int key=NULL;
	for (std::pair<int, double> i : koko) {
		if (inVec(i.first, repeat)) {
			continue;
		}
		else {
			if (i.second <= minimum) {
				minimum = i.second;
				key = i.first;
			}
		}
		
	}
	return key;
}