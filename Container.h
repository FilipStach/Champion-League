#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

template <typename T>
class Container {
protected:
    unordered_map<int, T*> elements;
public:
    Container(){};
    unordered_map<int, T*> getElements() const{return this->elements;};
    void deleteElement(int id){this->elements.erase(id);};
    bool contains(int id){return this->elements.count(id);};
};

//template <typename T>
//Container<T>::Container()
//{

//}
//template <typename T>
//unordered_map<int,T*> Container<T>::getElements() const{
//    return this->elements;
//}
//template <typename T>
//void Container<T>::deleteElement(int id){

//    this->elements.erase(id);
//}
//template <typename T>
//bool Container<T>::contains(int id){
//    return this->elements.count(id);
//}

