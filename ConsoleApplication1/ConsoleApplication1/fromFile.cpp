#include "fromFile.h"
std::vector<int> fromFile(std::string file_name) {
	std::ifstream stream(file_name);
	std::vector<int> start;
    int liczba;
    while (stream >> liczba) {
        start.push_back(liczba);
    }
    return start;
}