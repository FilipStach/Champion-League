#include "GoalKeeper.h"
#include "Defender.h"
#include "Midfielder.h"
#include "Striker.h"
#include "Coach.h"
#include "Club.h"
#include "iostream"
#include "FileReader.h"
using namespace std;
void changey(int &y){
    y=5;

}
int main()
{
    int value = 2000000;
    std::string photo = "filip.jpg";
    std::string name1[] = {"Filip", "Stach"};
    std::string name2[] = {"Ann", "Lex"};
    std::string name3[] = {"Filip", "Spurs"};
    std::string name4[] = {"Kanry", "Stach"};
    std::string coachName[]= {"Pep","Guardiola"};
    string tactics = "4-4-2";
    int skills = 5;
    int shooting = 56;
    int reflex = 42;
    int tackle = 23;
    int passes = 67;
    int headers = 89;
    Goalkeeper *goalkeeper = new Goalkeeper( value,name1,tackle, reflex);
    Defender *defender = new Defender( value,name2,headers,tackle);
    Midfielder *midfielder = new Midfielder( value,name3,shooting,passes,tackle);
    Striker *striker = new Striker( value,name4,shooting,passes,headers);
    Coach *coach = new Coach(coachName,  skills,  value, tactics);
    Club club(*goalkeeper,*defender,*midfielder,*striker, *coach);
    cout<<club.toString()<<endl;
    delete goalkeeper;
    delete defender;
    delete midfielder;
    delete striker;
    delete coach;
    cout<<club.toString()<<endl;
    int y=4;
    changey(y);
    cout<< club.toString()<<endl;


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
//#include "iostream"
//class COczko {
//public:
//COczko() { kolor = "szary"; }
//string dajKolor() { return kolor; }
//void changeColor() { kolor="niebieski";}
//private:
//string kolor;
//};
//class CMisio {
//private:
//COczko lewe;
//COczko prawe;
//public:
//COczko& dajLewe() { return lewe; }
//COczko& dajPrawe() { return prawe; }
//};
//int main() {
//CMisio misio;

//std::cout<<"Kolor oczka lewego: "+(misio.dajLewe()).dajKolor()+
//        "\nKolor oczka prawego: "+(misio.dajPrawe()).dajKolor()<<std::endl;
//};
//#include <string>
//#include "iostream"
//class CTowar
//{
//private:
//    int ilosc;
//    std::string nazwa;

//public:
//    CTowar()
//    {
//        nazwa = "";
//        ilosc = 0;
//    }
//    void setNazwa(std::string _n) { nazwa = _n; }
//    void setIlosc(int _i) { ilosc = _i; }
//    void pisz() { std::cout << nazwa << ", ilosc: " << ilosc; }

////    CTowar operator+(int const x){
////        this->ilosc+=x;
////        return *this;
////    }
//    CTowar operator+(int const x){
//        CTowar towar;
//        towar.setNazwa(this->nazwa);
//        towar.setIlosc(this->ilosc+x);
//        return towar;
//    }
//};

//int main()
//{
//    CTowar a;
//    a.setNazwa("jaja");
//    a.setIlosc(5);
//    a = a + 5;
//    a.pisz();
//};
