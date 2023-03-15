
#include "Defender.h"
#include "Coach.h"
#include "iostream"
#include "FileReader.h"
using namespace std;

int main()
{
    int value = 2000000;
    std::string photo = "filip.jpg";
    std::string name[] = {"Filip", "Stach"};
    std::string coachName[]= {"Pep","Guardiola"};
    int marking = 56;
    int tackle = 42;
    std::string tactics = "4-4-2";
    Defender defender(value, photo, name,marking, tackle);
    int skills = 5;
    value = 3000000;
    Coach coach(coachName,  skills,  value, tactics);
    FileReader fileReader;
    vector<vector<string>> output;
        output = fileReader.readFile("footballers.txt");
    cout<<"kaka"<<endl;
}
//#include <sstream>
//#include <iostream>
//#include <fstream>
//#include <vector>
//using namespace std;
//int main() {
//    string str;
//    vector<vector<string>> output;
//    fstream my_file;
////  std::vector<std::string> *vct = new std::vector<std::string>;
//    my_file.open("footballers.txt", ios::in);
//    if(my_file.is_open()) {
//        cout << "File created successfully!"<< endl;;
//        while (getline(my_file, str))
//        {
//            cout << str <<endl;
//            vector<string> vct;
//            string segment;
//            stringstream stream(str);
//            cout << "im in file!"<<endl;
//            if(str.size() > 0){
//                while(getline(stream, segment, ';'))
//                {
//                    cout << "im in file!"<<endl;
//                   vct.push_back(segment);
//                }
//            }
//            output.push_back(vct);
//        }
//        my_file.close();
//    }
//}
//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;

//int main()
//{
//    fstream myFile;
//    myFile.open("footballers.txt",ios::in);
//    if (myFile.is_open()){
//        string line;
//        cout <<"file open"<<endl;
//        while(getline(myFile,line)){
//            cout <<line<<endl;

//        }
//        myFile.close();
//    }
//    system("pause>0");


