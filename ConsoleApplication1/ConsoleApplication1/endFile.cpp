#include "endFile.h"
/**
* @brief funkcja dopisuje do zadanego pliku.
* @param file_text nazwa pliku wynikowego w ktorym chcemy zapisac dane
* @param wynik dane do zapisu w pliku
*/
void endFile(std::string file_text, std::vector<std::string> wynik) {
    std::ofstream stream(file_text, std::ios_base::app);
    for (const auto& line : wynik) {
        stream << line << "\n";
    }
    stream.close();
}