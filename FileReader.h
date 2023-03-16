#pragma once
#include <vector>

#include <string>
class FileReader
{
private:

public:
    FileReader();
    std::vector<std::vector<std::string>> readFile(std::string file);
};
