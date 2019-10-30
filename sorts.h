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
    void QuickSort(int inicio, int final);
};

template <class T>
int Sorts<T>::size() {
    return deserializador->getElementos()->size();
}

template <class T>
int Sorts<T>::particion(int inicio, int final){
    int x = elementos->at(final)->getTradeUsd();
    int i = inicio-1;
    for (int j = inicio; j < final;j++){
        if(elementos->at(j)->getTradeUsd() < x){
            i++;
            iter_swap(elementos->operator[](i),elementos->operator[](j));
        }
    }
    iter_swap(elementos->operator[](i+1),elementos->operator[](final));
    return i+1;
}

template <class T>
void Sorts<T>::QuickSort(int inicio, int final) {
    if(inicio < final){
        int p = particion(inicio,final);
        QuickSort(inicio,p-1);
        QuickSort(p+1,final);
    }
}
/*
template <class T>
void Sorts<T>::QuickSort(int inicio, int final) {
    if(inicio < final){
        int p = particion(inicio,final);
        QuickSort(inicio,p-1);
        QuickSort(p+1,final);
    }
}
*/
template <class T>
Sorts<T>::Sorts(const string& nombreArchivo) {
    serializador = new serializadorCountry<T>();
    deserializador = new deserializadorCountry();

    fstream* archivo = new fstream(nombreArchivo,ios_base::in);
    string linea;
    getline(*archivo,linea);

    if(archivo){
        while(getline(*archivo,linea)){
            Country* country = deserializador->Deserializar(linea,',');
            deserializador->getElementos()->push_back(country);
        }
        archivo->close();
    }
    elementos = deserializador->getElementos();
    delete archivo;
}

template <class T>
void Sorts<T>::mostrarElementos() {
    for (auto country: *deserializador->getElementos()){
        cout << country->getCountryName() << " ";
        cout << country->getYear() << " ";
        cout << country->getCommCode() << " ";
        cout << country->getCommodity() << " ";
        cout << country->getFlow() << " ";
        cout << country->getTradeUsd() << " ";
        cout << country->getWeight() << " ";
        cout << country->getQuantityName() << " ";
        cout << country->getQuantity() << " ";
        cout << country->getCategory() << endl;
    }
}

template <class T>
void Sorts<T>::listar(const string & nombreArchivo) {
    fstream* archivo = new fstream(nombreArchivo,ios_base::out);
    if(archivo){
        for (Country* country: *deserializador->getElementos()){
            *archivo << serializador->Serializar(country,",") <<endl;
            cout << country->getCountryName() << " ";
            cout << country->getYear() << " ";
            cout << country->getCommCode() << " ";
            cout << country->getCommodity() << " ";
            cout << country->getFlow() << " ";
            cout << country->getTradeUsd() << " ";
            cout << country->getWeight() << " ";
            cout << country->getQuantityName() << " ";
            cout << country->getQuantity() << " ";
            cout << country->getCategory() << endl;
        }
        archivo->close();
    }
    delete archivo;
}

template <class T>
void Sorts<T>::listarCountries() {
    listar("QuickSort.csv");

}

//Destructor
template <class T>
Sorts<T>::~Sorts() {
    delete deserializador;
    delete serializador;
}


#endif //MINI_P2_SORTS_H
