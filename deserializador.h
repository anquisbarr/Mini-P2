//
// Created by Sebastian Q.B on 29/10/2019.
//

#ifndef MINI_P2_DESERIALIZADOR_H
#define MINI_P2_DESERIALIZADOR_H

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Deserializador{
protected:
    vector <T*>* elementos;
public:
    Deserializador();
    ~Deserializador();
    vector<T*>* getElementos();
    virtual T* Deserializar(const string&,char)=0;
};

template <class T>
Deserializador<T>::Deserializador() {
    elementos = new vector<T*>();
}

template <class T>
Deserializador<T>::~Deserializador() {
    for(auto elemento : *elementos)
        delete elemento;
    delete elementos;
}

template <class T>
vector<T*>* Deserializador<T>::getElementos() {
    return elementos;
}

#endif //MINI_P2_DESERIALIZADOR_H
