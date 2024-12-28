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
#include "wszystkieW.h"
#include "connections.h"
#include "dijkstry.h"
#include "endFile.h"
#include "fromFile.h"

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






int main()
{

    open_file("znaki.txt");
    std::map<int, std::map<int, double>> grafek = connections(wierzcholkiPoczatkowe, wierzcholkiKoncowe, kierunki, wagi);
    std::vector<std::vector<std::string>> dijkstryList;
    for (auto num : fromFile("poczatki.txt") ){
        dijkstryList.push_back(dijkstry(grafek, num, wierzcholkiPoczatkowe, wierzcholkiKoncowe));
    }
    for (auto i : dijkstryList) {
        endFile("wyniki.txt", i);
    }

}

