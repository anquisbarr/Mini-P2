//
// Created by Sebastian Q.B on 29/10/2019.
//

#ifndef MINI_P2_SORTS_H
#define MINI_P2_SORTS_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "serializadorCountry.h"
#include "deserializadorCountry.h"
using namespace std;

template <class T>
class Sorts{
protected:
    Serializador<T>* serializador;
    Deserializador<T>* deserializador;
    void listar(const string&);
    int particion(int inicio, int final);
    vector<T*>* elementos;
public:
    Sorts(const string&);
    int size();
    ~Sorts();
    void mostrarElementos();
    void listarCountries();
};

template <class T>
int Sorts<T>::size() {
    return deserializador->getElementos()->size();
}

template <class T>
int Sorts<T>::particion(int inicio, int final){
    int x = elementos->at(final)->getTradeUsd();
}


#endif //MINI_P2_SORTS_H
