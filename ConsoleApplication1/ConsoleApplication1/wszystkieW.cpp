#include "wszystkieW.h"
/**
* @brief funkcja zwracajaca wszystkie wierzcholki na podstawie wierzcholkow poczatkowych oraz koncowych.
* @param wierzcholkiP zbior wierzcholkow poczatkowych
* @param wierzcholkiK zbior wierzcholkow koncowych
* @return wektor z wszystkimi wierzcholkami
*/
std::vector<int> wszystkieW(std::vector<int> wierzcholkiP, std::vector<int> wierzcholkiK) {
    std::vector<int>  wektor;
    for (int x : wierzcholkiP) {
        if (std::find(wektor.begin(), wektor.end(), x) == wektor.end()) {
            wektor.push_back(x);
        }
    }
    for (int x : wierzcholkiK) {
        if (std::find(wektor.begin(), wektor.end(), x) == wektor.end()) {
            wektor.push_back(x);
        }
    }
    return wektor;
}