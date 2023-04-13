#pragma once
#include <vector>

#include <string>
/**

@class FileReader
@brief Klasa umożliwiająca odczyt pliku.
Klasa FileReader umożliwia odczyt pliku i zwrócenie jego zawartości w postaci
wektora wektorów stringów. Każdy wewnętrzny wektor zawiera dane z jednego wiersza,
a każdy element tego wektora to pojedynczy wyraz z tego wiersza.
*/
class FileReader
{
private:

public:
    FileReader();
    static std::vector<std::vector<std::string>> readFile(std::string file);
};
