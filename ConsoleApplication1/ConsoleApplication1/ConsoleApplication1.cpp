// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


//##6 Dijkstra
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <array>

int wierzcholki1[5];
int wierzcholki2[5];
std::string kierunki[5];
double wagi[5];

//std::string open_file(std::string file_text, int line) {
//    std::ifstream stream(file_text);
//    std::string word;
//    while (std::getline(stream, word)) {
//        
//    }
//    
//}



int main()
{

    std::ifstream stream("znaki.txt");
    std::ofstream out("test.txt");
    std::string word;
    int liczba1,liczba2;
    std::string kierunek;
    char znak;
    double dlugosc;
    int i = 0;
    while (stream>>liczba1>>kierunek>>liczba2>>znak>>dlugosc){
        wierzcholki1[i] = liczba1;
        wierzcholki2[i] = liczba2;
        kierunki[i] = kierunek;
        wagi[i] = dlugosc;


        i++;
    }
    for (int i = 0; i < 5; i++) {
        std::cout << wierzcholki1[i]<< kierunki[i] << wierzcholki2[i]<<":" << wagi[i] << std::endl;
    }

}

