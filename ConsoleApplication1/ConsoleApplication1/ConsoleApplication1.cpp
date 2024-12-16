// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


//##6 Dijkstra
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <array>
#include <vector>
#include <map>

#include "min.h"
#include "sasiedzi.h"
std::vector<int> wierzcholkiPoczatkowe;
std::vector<int> wierzcholkiKoncowe;
std::vector <std::string> kierunki;
std::vector<double> wagi;
std::vector<int> Q1;

/**
* funkcja odczytuje linie pliku pomijajac biale znaki, wartości wpisuje do odpowiadającego vectora
*@param file_text nazwa pliku do odczytu
**/
void open_file(std::string file_text) {
    std::ifstream stream(file_text);
    int liczba1, liczba2;
    std::string kierunek;
    char znak;
    double dlugosc;
    while (stream >> liczba1 >> kierunek >> liczba2 >> znak >> dlugosc) {
        wierzcholkiPoczatkowe.push_back(liczba1);
        wierzcholkiKoncowe.push_back(liczba2);
        kierunki.push_back(kierunek);
        wagi.push_back(dlugosc);
    }
}

std::map<int, std::map<int, double>> connections() {
    std::map<int, std::map<int, double>> graph;
    for (int i = 0; i < wierzcholkiPoczatkowe.size();i++) {
        if(kierunki[i]=="->" or kierunki[i]=="-")
            graph[wierzcholkiPoczatkowe[i]][wierzcholkiKoncowe[i]] = wagi[i];
        if(kierunki[i] == "-")
            graph[wierzcholkiKoncowe[i]][wierzcholkiPoczatkowe[i]] = wagi[i];

    }
    return graph;
}
std::vector<int> wszystkieW() {
    std::vector<int>  wektor;
    for (int x : wierzcholkiPoczatkowe) {
        if (std::find(wektor.begin(), wektor.end(), x) == wektor.end()) {
            wektor.push_back(x);
        }
    }
    for (int x : wierzcholkiKoncowe) {
        if (std::find(wektor.begin(), wektor.end(), x) == wektor.end()) {
            wektor.push_back(x);
        }
    }
    return wektor;
}

void dijkstry(std::map<int, std::map<int, double>> graph, int v) {
    double finalnaWaga=0;
    std::vector<int> S;
    std::vector<int> Q= wszystkieW();
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
        for (int wierzcholekW : sasiedzi(graph, wszystkieW(), wierzcholekU)) {
            if (std::distance(Q.begin(), std::find(Q.begin(), Q.end(), wierzcholekW)) == Q.size())
                continue;
            if (d[wierzcholekW] > d[wierzcholekU] + graph[wierzcholekU][wierzcholekW]) {
                d[wierzcholekW] = d[wierzcholekU] + graph[wierzcholekU][wierzcholekW];
                p[wierzcholekW] = wierzcholekU;
            }

        }

    }
    std::cout << "Wierzcholek startowy " << v << ":\n";
    for (auto [dest, koszt] : d) {
        if (koszt == DBL_MAX or koszt == 0) {// Nie wyswietlaj dla nieskonczonosci i samej siebie
            continue;
        }

        // Rekonstrukcja ścieżki
        std::vector<int> sciezka;
        int current = dest;
        while (current != -1) {
            sciezka.push_back(current);
            current = p[current];
        }

        
        std::reverse(sciezka.begin(), sciezka.end());// Odwrócenie ścieżki

        std::cout << v;
        for (int i = 1; i < sciezka.size(); ++i) {
            std::cout << " -> " << sciezka[i];
        }
        std::cout << " : "<< koszt << "\n";
    }
}

int main()
{
    open_file("znaki.txt");
    std::map<int, std::map<int, double>> grafek = connections();
    dijkstry(grafek, 1);

}

