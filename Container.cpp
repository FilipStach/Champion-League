#include "Coach.h"
#include "Defender.h"
#include "GoalKeeper.h"
#include "Midfielder.h"
#include "Striker.h"
#include <iostream>
#include <Container.h>

using namespace std;

template <typename T>
Container<T>::Container()
{

}
//template <typename T>
//Container<T>::Container(vector<vector<string>> data){
//    string name[2];
//    int qualifier;
//    for(vector<string> element : data){
//        qualifier = stoi(element[0])%5;
//        switch(qualifier){
//            case 0:
//                name[0] = element[1];
//                name[1] = element[2];
//                this->elements[stoi(element[0])] = new Coach(name, stoi(element[3]), stoi(element[4]), element[5],stoi(element[0]));
//                break;
//            case 1:
//                name[0] = element[2];
//                name[1] = element[3];
////                this->elements[stoi(element[0])] = new Goalkeeper(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[0]));
//                break;
//            case 2:
//                name[0] = element[2];
//                name[1] = element[3];
////                this->elements[stoi(element[0])] = new Defender(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[0]));
//                break;
//            case 3:
//                name[0] = element[2];
//                name[1] = element[3];
////                this->elements[stoi(element[0])] = new Midfielder(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[6]),stoi(element[0]));
//                break;
//            case 4:
//                name[0] = element[2];
//                name[1] = element[3];
////                this->elements[stoi(element[0])] = new Striker(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[6]),stoi(element[0]));
//                break;
//            default:
//                cout<<"Something want wrong while assigning elements"<<endl;
//                break;
//        }
//    }
//}
template <typename T>
unordered_map<int,T*> Container<T>::getElements() const{
    return this->elements;
}
template <typename T>
void Container<T>::deleteElement(int id){

    this->elements.erase(id);
}
//Container<T>::~Container(){
//    unordered_map<int, T*>::iterator it = elements.begin();
//    while (it != elements.end()) {
//           delete it->second;
//           it++;
//       }
//}
template <typename T>
bool Container<T>::contains(int id){
    return this->elements.count(id);
}
