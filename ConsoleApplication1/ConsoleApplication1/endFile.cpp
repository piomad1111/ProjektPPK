#include "endFile.h"
void endFile(std::string file_text, std::vector<std::string> wynik) {
    std::ofstream stream(file_text, std::ios_base::app);
    for (const auto& line : wynik) {
        stream << line << "\n";
    }
    stream.close();
}