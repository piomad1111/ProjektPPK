#include <vector>
#include "vec.h"
bool inVec(int x, std::vector<int> vec) {
	for (auto i : vec) {
		if (i == x)
			return true;
	}
	return false;
}