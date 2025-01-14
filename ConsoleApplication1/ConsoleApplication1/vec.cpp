#include <vector>
#include "vec.h"
/**
* @brief funkcja sprawdzajaca czy wartosc jest w wektorze
* @param x wartosc szukana
* @param vec wektor do przeszukania
*/
bool inVec(int x, std::vector<int> vec) {
	for (auto i : vec) {
		if (i == x)
			return true;
	}
	return false;
}