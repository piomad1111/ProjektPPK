#pragma once
#include "connections.h"
#include "wszystkieW.h"
#include "min.h"
#include "sasiedzi.h"
std::vector<std::string> dijkstry(std::map<int, std::map<int, double>> graph, int v, std::vector<int> wierzcholkiPoczatkowe, std::vector<int> wierzcholkiKoncowe);