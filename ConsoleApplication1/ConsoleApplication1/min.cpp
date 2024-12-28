#include "min.h"
double min(std::map<int, double> koko, std::vector<int> repeat) {
	double minimum = DBL_MAX;
	int key = NULL;
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