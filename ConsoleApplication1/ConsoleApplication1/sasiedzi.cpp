#include "sasiedzi.h"
/**
* @brief Funkcja znajdje sasiadujace wierzcholki w grafie.
* @param baseW mapa z grafem
* @param wszystkieW wszystkie wierzcholki w grafie @see wszystkieW.cpp
* @param startV wierzcho³ek startowy
* @return wektor z sasiadujacymi wierzcholkami
*/
std::vector<int> sasiedzi(std::map<int, std::map<int, double>> baseW, std::vector<int>wszystkieW, int startV) {
	std::vector<int> sasiedzi;
	for (int j : wszystkieW) {
		if (baseW[startV][j] > 0)
			sasiedzi.push_back(j);
	}

	return sasiedzi;
}