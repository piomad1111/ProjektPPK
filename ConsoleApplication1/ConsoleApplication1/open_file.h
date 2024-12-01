#pragma once
#include <vector>
#include <string>
#include <fstream>

std::vector<int> wierzcholkiPoczatkowe;
std::vector<int> wierzcholkiKoncowe;
std::vector <std::string> kierunki;
std::vector<double> wagi;

/**
* funkcja odczytuje linie pliku pomijajac biale znaki, wartoœci wpisuje do odpowiadaj¹cego vectora
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
