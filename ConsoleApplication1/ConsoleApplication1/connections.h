#pragma once
#include <map>
#include <vector>
#include <string>
std::map<int, std::map<int, double>> connections(std::vector<int> wierzcholkiPoczatkowe, std::vector<int> wierzcholkiKoncowe, std::vector <std::string> kierunki, std::vector<double> wagi);