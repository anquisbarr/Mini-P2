//
// Created by chrisis on 1/11/19.
//

#ifndef MINI_P2_SUMARIZAR_H
#define MINI_P2_SUMARIZAR_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "serializadorCountry.h"
#include "deserializadorCountry.h"
using namespace std;


class Palabra{
private:
    string palabra;
    unsigned int contador;
public:
    Palabra(const string &palabra, unsigned int contador) : palabra(palabra), contador(contador) {}

    const string &getPalabra() const {
        return palabra;
    }

    unsigned int getContador() const {
        return contador;
    }
};


template <class T>
class Sumarizar{
private:
    Serializador<T>* serializador;
    Deserializador<T>* deserializador;
    void listar(const string&);
    vector<T*>* elementos;
public:
    Sumarizar(const string&);
    void sumarizacion1();
    void sumarizacion2();

    void listarCountries();
    ~Sumarizar();


};

template <class T>
Sumarizar<T>::Sumarizar(const string& nombreArchivo) {
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
void Sumarizar<T>::sumarizacion1() {
    vector<int> *llave = new vector<int>();
    for (int x = 0;x < elementos->size(); x++){
        int y = elementos->at(x)->getTradeUsd;
        //string z = to_string(elementos->at(x)->getYear);
        llave->push_back(y);
    }

    for (auto x : *llave){
        cout << x << endl;
    }
    delete llave;
}

template <class T>
void Sumarizar<T>::listar(const string & nombreArchivo) {
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
void Sumarizar<T>::listarCountries() {
    listar("QuickSort.csv");

}

template <class T>
Sumarizar<T>::~Sumarizar() {
    delete deserializador;
    delete serializador;
}

#endif //MINI_P2_SUMARIZAR_H
