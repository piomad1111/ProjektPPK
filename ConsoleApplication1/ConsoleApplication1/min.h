#pragma once
#include <map>

double min(std::map<int, double> koko) {
	double minimum=DBL_MAX;
	int key=NULL;
	for (std::pair<int, double> i : koko) {
		if (i.second <= minimum) {
			minimum = i.second;
			key = i.first;

		}
	}
	return key;
}