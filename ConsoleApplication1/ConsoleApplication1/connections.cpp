#include "connections.h"
std::map<int, std::map<int, double>> connections(std::vector<int> wierzcholkiPoczatkowe, std::vector<int> wierzcholkiKoncowe, std::vector <std::string> kierunki, std::vector<double> wagi) {
    std::map<int, std::map<int, double>> graph;
    for (int i = 0; i < wierzcholkiPoczatkowe.size();i++) {
        if (kierunki[i] == "->" or kierunki[i] == "-")
            graph[wierzcholkiPoczatkowe[i]][wierzcholkiKoncowe[i]] = wagi[i];
        if (kierunki[i] == "-")
            graph[wierzcholkiKoncowe[i]][wierzcholkiPoczatkowe[i]] = wagi[i];

    }
    return graph;
}