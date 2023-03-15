#ifndef FILEREADER_H
#define FILEREADER_H
#include <vector>

#include <string>
class FileReader
{
private:

public:
    FileReader();
    std::vector<std::vector<std::string>> readFile(std::string file);
};

#endif // FILEREADER_H
