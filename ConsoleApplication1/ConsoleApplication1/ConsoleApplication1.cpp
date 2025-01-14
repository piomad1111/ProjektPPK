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
* @brief funkcja odczytuje linie pliku pomijajac biale znaki, wartości wpisuje do odpowiadającego vectora.
*@param file_text nazwa pliku do odczytu
*/
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






int main(int argc, char* argv[])
{
    std::string inGraf, inWierzcholki, outWynik;
    if (argc < 7 or argc >7) {
        std::cout << "Progra do znajdowania najkrotszych sciezek miedzy zadanym wierzcholkiem grafu a wszystkimi pozostalymi wierzcholkami tego grafu. Program wykorzystuje algorytm Dijkstry.\n ***PROGRAM DZIALA W TRYBIE DOPISYWANIA DO PLIKU***  \n -g plik wejsciowy z grafem \n -w plik wejsciowy z wierzcholkami \n -o plik wyjsciowy z wynikami \n";
    }
    else {
        std::string tablica[7];
        for (int i = 0; i < argc;i++) {
            tablica[i] = argv[i];
        }
        for (int j = 0; j < 7;j++) {
            if (tablica[j] == "-g")
                inGraf = tablica[j + 1];
            else if (tablica[j] == "-w")
                inWierzcholki = tablica[j + 1];
            else if (tablica[j] == "-o")
                outWynik = tablica[j + 1];

        }
    }
    open_file(inGraf);
    std::map<int, std::map<int, double>> grafek = connections(wierzcholkiPoczatkowe, wierzcholkiKoncowe, kierunki, wagi);
    std::vector<std::vector<std::string>> dijkstryList;
    for (auto num : fromFile(inWierzcholki) ){
        dijkstryList.push_back(dijkstry(grafek, num, wierzcholkiPoczatkowe, wierzcholkiKoncowe));
    }
    for (auto i : dijkstryList) {
        endFile(outWynik, i);
    }
    std::cout << "Mozesz zamknac to okno" << std::endl;

}

//"Progra do znajdowania najkrótszych ścieżek między zadanym wierzchołkiem grafu a wszystkimi pozostałymi wierzchołkami tego grafu. Program wykorzystuje algorytm Dĳkstry \n -g plik wejściowy z grafem \n -w plik wejściowy z wierzchołkami \n -o plik wyjściowy z wynikami"



