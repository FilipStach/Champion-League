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
    Container();
    unordered_map<int, T*> getElements() const;
    void deleteElement(int id);
    bool contains(int id);
};
