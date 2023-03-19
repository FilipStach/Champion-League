#pragma once
#include <vector>

#include <string>
class FileReader
{
private:

public:
    FileReader();
    static std::vector<std::vector<std::string>> readFile(std::string file);
};
