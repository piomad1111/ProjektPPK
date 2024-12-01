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

std::vector<int> wierzcholkiPoczatkowe;
std::vector<int> wierzcholkiKoncowe;
std::vector <std::string> kierunki;
std::vector<double> wagi;
std::vector<int> Q;

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

void dijkstry() {

}

int main()
{
    open_file("znaki.txt");
    std::map<int, std::map<int, double>> grafek = connections();
    /*for (int i = 0; i < wierzcholkiPoczatkowe.size(); i++) {
        std::cout << wierzcholkiPoczatkowe[i]<< kierunki[i] << wierzcholkiKoncowe[i]<<":" << wagi[i] << std::endl;
    }*/
    
    /*for (auto i : wierzcholkiPoczatkowe) {
         std::cout << std::endl;
    }*/


    Q = wszystkieW();
    for (int i : Q) {
        for (int j : Q) {
            if(grafek[i][j]!=0)
            std::cout << i<<" : "<<j<<" = "<<grafek[i][j] << std::endl;

        }
    }
    std::cout << grafek.size();
   
}

