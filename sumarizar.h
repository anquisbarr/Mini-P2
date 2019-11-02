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
#include <map>
using namespace std;



template <class T>
class Sumarizar{
private:
    Serializador<T>* serializador;
    Deserializador<T>* deserializador;
    void listar1(const string&);
    void listar2(const string&);
    vector<T*>* elementos;
    map<string,int>* result1;
    map<string,int>* result2;
public:
    Sumarizar(const string&);
    void sumarizacion1();
    void sumarizacion2();

    void listarResult1();
    void listarResult2();
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
    vector<string> *llave = new vector<string>();
    for (int x = 0;x < elementos->size(); x++){
        string y = elementos->at(x)->getCountryName();
        string z = to_string(elementos->at(x)->getYear());
        llave->push_back(y + " " + z);
    }

    result1 = new map<string,int>();
    ;
    for (int x = 0; x < elementos->size(); x++){
        (*result1)[llave->at(x)] += elementos->at(x)->getTradeUsd();
    }

    for (auto it = result1->begin(); it != result1->end(); it ++){
        cout << it->first << ": " << it->second << endl;
    }


    delete llave;
}

template <class T>
void Sumarizar<T>::sumarizacion2() {
    vector<string> *llave2 = new vector<string>();
    for (int x = 0;x < elementos->size(); x++){
        string y = elementos->at(x)->getCountryName();
        string z = to_string(elementos->at(x)->getYear());
        string a = elementos->at(x)->getFlow();
        llave2->push_back(y + " " + z + " " + a);
    }

    result2 = new map<string,int>();

    for (int x = 0; x < elementos->size(); x++){
        (*result2)[llave2->at(x)] += elementos->at(x)->getTradeUsd();
    }

    for (auto it = result2->begin(); it != result2->end(); it ++){
        cout << it->first << ": " << it->second << endl;
    }

    delete llave2;
}

template <class T>
void Sumarizar<T>::listar1(const string & nombreArchivo) {
    fstream* archivo = new fstream(nombreArchivo,ios_base::out);
    if(archivo) {
        for (auto it = result1->begin(); it != result1->end(); it ++){
            *archivo << it->first << ": " << it->second << endl;
        }
        archivo->close();
    }
}

template <class T>
void Sumarizar<T>::listar2(const string & nombreArchivo) {
    fstream* archivo = new fstream(nombreArchivo,ios_base::out);
    if(archivo) {
        for (auto it = result2->begin(); it != result2->end(); it ++){
            *archivo << it->first << ": " << it->second << endl;
        }
        archivo->close();
    }
}

template <class T>
void Sumarizar<T>::listarResult1() {
    listar1("sumarizacion1.txt");
}

template <class T>
void Sumarizar<T>::listarResult2() {
    listar2("sumarizacion2.txt");
}

template <class T>
Sumarizar<T>::~Sumarizar() {
    delete deserializador;
    delete serializador;
}

#endif //MINI_P2_SUMARIZAR_H
