#include "min.h"
/**
* @brief funckja do znajdywania klucza z zajmniejszej wartosci mapy z pominieciem zadanych kluczy
* 
*@param find mapa w ktorej chcemy klucz z najmniejszej wartosci wartosci 
*@param repeat wektor kluczy do pominiecia
*@return klucz najmniejszej wartosci
*/
double min(std::map<int, double> find, std::vector<int> repeat) {
	double minimum = DBL_MAX;
	int key = NULL;
	for (std::pair<int, double> i : find) {
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