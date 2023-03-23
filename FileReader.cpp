#include "FileReader.h"
#include "fstream"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
FileReader::FileReader()
{

}

vector<vector<string>> FileReader::readFile(string fileName){
    vector<vector<string>> output;
//    std::ifstream in("footballers.txt");
    fstream in;
    in.open(fileName, ios::in);
    if(in.is_open()){
        string str;
        while (getline(in, str))
        {
    //        std::vector<std::string> *vct = new std::vector<std::string>;
            vector<string> vct;
            string segment;
            stringstream stream(str);
            if(str.size() > 0){
                while(getline(stream, segment, ';'))
                {

                   vct.push_back(segment);
                }
            }
            output.push_back(vct);
        }
        in.close();
        return output;
    }
    else{
            cout <<"Couldnt open file "<< endl;
            exit;
        }

}
