#include "wszystkieW.h"
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