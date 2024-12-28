#include "sasiedzi.h"
std::vector<int> sasiedzi(std::map<int, std::map<int, double>> baseW, std::vector<int>wszystkieW, int startV) {
	std::vector<int> sasiedzi;
	for (int j : wszystkieW) {
		if (baseW[startV][j] > 0)
			sasiedzi.push_back(j);
	}

	return sasiedzi;
}