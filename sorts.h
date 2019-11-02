//
// Created by Sebastian Q.B on 29/10/2019.
//

#ifndef MINI_P2_SORTS_H
#define MINI_P2_SORTS_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "serializadorCountry.h"
#include "deserializadorCountry.h"
using namespace std;

template <class T>
class Sorts{
protected:
    Serializador<T>* serializador;
    Deserializador<T>* deserializador;
    void heapify(int n);
    void listar(const string&);
    int particion(int inicio, int final);
    vector<T*>* elementos;
public:
    Sorts(const string&);
    int size();
    void heapify(auto size,int i);
    ~Sorts();
    void mostrarElementos();
    void listarCountries(int n);
    void QuickSort(int inicio, int final);
    void ShellSort();
    void HeapSort(int size);
    void MergeSort();
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

//ESCRIBIR EN EL ARCHIVO
template <class T>
void Sorts<T>::listar(const string & nombreArchivo) {
    fstream* archivo = new fstream(nombreArchivo,ios_base::out);
    if(archivo){
        for (Country* country: *deserializador->getElementos()){
            *archivo << serializador->Serializar(country,",") <<endl;
            // Provisional code for sorting and reading
            /*cout << country->getCountryName() << " ";
            cout << country->getYear() << " ";
            cout << country->getCommCode() << " ";
            cout << country->getCommodity() << " ";
            cout << country->getFlow() << " ";
            cout << country->getTradeUsd() << " ";
            cout << country->getWeight() << " ";
            cout << country->getQuantityName() << " ";
            cout << country->getQuantity() << " ";
            cout << country->getCategory() << endl;
             */
        }
        archivo->close();
    }
    delete archivo;
}

template <class T>
void Sorts<T>::listarCountries(int n) {
    switch(n){
        case 1:
            listar("QuickSort.csv");break;
        case 2:
            listar("ShellSort.csv");break;
        case 3:
            listar("HeapSort.csv");break;
        case 4:
            listar("MergeSort.csv");break;

    }

}

//Destructor
template <class T>
Sorts<T>::~Sorts() {
    delete deserializador;
    delete serializador;
}
template<class T>
void Sorts<T>::heapify(auto size, int node){
      int smallest = node; // Inicializa el más pequeño como root(raiz)
      int l = 2*node + 1; //left = 2*node + 1
      int r = 2*node + 2; //right = 2*node +2

      // Si el hijo izquierdo es más pequeño que la raíz
      if (l < size && elementos->at(l)->getTradeUsd() < elementos->at(smallest)->getTradeUsd())
          smallest = l;

      // Si el hijo derecho es más pequeño que el más pequeño hasta ahora
      if (r < size && elementos->at(r)->getTradeUsd() < elementos->at(smallest)->getTradeUsd())
          smallest = r;

      // Si el más pequeño no es la raíz
      if (smallest != node) {
          std::swap(elementos[node], elementos[smallest]);
          // Usa heapify recursivamente
          heapify(size, smallest);
      } 
}





#endif //MINI_P2_SORTS_H
