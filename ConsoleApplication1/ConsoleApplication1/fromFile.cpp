#include "fromFile.h"
/**
* @brief funkcja pobiera wartosci wierzcholkow poczatkowych z pliku.
* @param file_name nazwa pliku z ktorego pobierzemy dane wejsciowe
* @return wektor z wierzcholkami startowymi
*/
std::vector<int> fromFile(std::string file_name) {
	std::ifstream stream(file_name);
	std::vector<int> start;
    int liczba;
    while (stream >> liczba) {
        start.push_back(liczba);
    }
    return start;
}