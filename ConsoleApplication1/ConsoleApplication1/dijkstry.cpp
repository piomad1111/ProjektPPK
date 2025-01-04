#include "dijkstry.h"
#include <iostream>

std::vector<std::string> dijkstry(std::map<int, std::map<int, double>> graph, int v, std::vector<int> wierzcholkiPoczatkowe, std::vector<int> wierzcholkiKoncowe) {
    double finalnaWaga = 0;
    std::vector<int> S;
    std::vector<int> Q = wszystkieW(wierzcholkiPoczatkowe, wierzcholkiKoncowe);
    if (std::distance(Q.begin(), std::find(Q.begin(), Q.end(), v)) == Q.size()) {
        std::vector<std::string> brak;
        brak.push_back("wierzcholek startowy " + std::to_string(v));
        brak.push_back("Brak wierzcholka "+std::to_string(v) + " w grafie");
        return brak;
    }
    std::map<int, double> d; //koszty dojscia
    std::map<int, int> p; //poprzedniki
    for (int i : Q) {
        d[i] = DBL_MAX; //ustawienie koosztu na najwiekszy dla kazdej wartosci
        p[i] = -1;      //brak poprzednika
    }
    d[v] = 0;// koszt do samego siebie
    while (!Q.empty()) {
        auto indexFind = std::find(Q.begin(), Q.end(), min(d, S));
        long int index = std::distance(Q.begin(), indexFind);
        int wierzcholekU = Q[index];
        S.push_back(wierzcholekU);
        Q.erase(indexFind);
        for (int wierzcholekW : sasiedzi(graph, wszystkieW(wierzcholkiPoczatkowe, wierzcholkiKoncowe), wierzcholekU)) {
            if (std::distance(Q.begin(), std::find(Q.begin(), Q.end(), wierzcholekW)) == Q.size())
                continue;
            if (d[wierzcholekW] > d[wierzcholekU] + graph[wierzcholekU][wierzcholekW]) {
                d[wierzcholekW] = d[wierzcholekU] + graph[wierzcholekU][wierzcholekW];
                p[wierzcholekW] = wierzcholekU;
            }

        }

    }
    std::vector<std::string> results;
    results.push_back("Wierzcholek startowy "+std::to_string(v));
    for (auto [dest, koszt] : d) {
        if (koszt == DBL_MAX or koszt == 0) {// Nie wyswietlaj dla nieskonczonosci i samej siebie
            continue;
        }

        // Rekonstrukcja sciezki
        std::vector<int> sciezka;
        int current = dest;
        while (current != -1) {
            sciezka.push_back(current);
            current = p[current];
        }

        std::reverse(sciezka.begin(), sciezka.end());// Odwrócenie sciezki

        std::string result = std::to_string(v);
        for (int i = 1; i < sciezka.size(); ++i) {
            result += " -> " + std::to_string(sciezka[i]);
        }
        result += " : " + std::to_string(koszt);

        results.push_back(result);
    }

    return results;
}