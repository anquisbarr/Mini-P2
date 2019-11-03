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
    ~Sorts();
    void mostrarElementos();
    void listarCountries(int n);
    void QuickSort(int inicio, int final);
    void ShellSort();
    void heapify(int,int,string);
    void heapSort(string);
    void mergeSort(int,int,string);
    void merge(int,int,int,string);
    void heapSortTradeUsd();
    void heapSortCriterio2();
    void mergeSortTradeUsd();
    void mergeSortCriterio2();
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
        case 5:
            listar("QuickSort-criterio2.csv");break;
        case 6:
            listar("ShellSort-criterio2.csv");break;
        case 7:
            listar("HeapSort-criterio2.csv");break;
        case 8:
            listar("MergeSort-criterio2.csv");break;

    }

}

//Destructor
template <class T>
Sorts<T>::~Sorts() {
    delete deserializador;
    delete serializador;
}



template <class T>
void Sorts<T>::QuickSort(int inicio, int final) {

    if(inicio < final){
        int p = particion(inicio,final);
        QuickSort(inicio,p-1);
        QuickSort(p+1,final);
    }
}

template<class T>
void Sorts<T>::ShellSort(){
    for (int k= size()/2; k > 0; k /= 2){
        for (int i = k; i < size(); i += 1){
            int temp = elementos->at(i)->getTradeUsd();//arr[i];
            auto obj_temp = elementos->at(i);//arr[i];
            int j;
            for (j = i; j >= k && elementos->at(j - k)->getTradeUsd() > temp; j -= k)
                elementos->at(j) = elementos->at(j - k);
            elementos->at(j) = obj_temp;
        }
    }
}


//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
// METODOS NECESARIOS PARA EL HEAP-SORT
template<class T>
void Sorts<T>::heapify(int n, int i,string criterio)
{
    if (criterio == "TradeUsd") {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
        // If left child is larger than root
        if (l < n && elementos->at(l)->getTradeUsd() < elementos->at(largest)->getTradeUsd())
            largest = l;

        // If right child is larger than largest so far
        if (r < n && elementos->at(r)->getTradeUsd() < elementos->at(largest)->getTradeUsd())
            largest = r;

        // If largest is not root
        if (largest != i) {
            swap(elementos->at(i), elementos->at(largest));

            // Recursively heapify the affected sub-tree
            heapify(n, largest,criterio);
        }
    }
    if (criterio == "Criterio2") {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
        // If left child is larger than root
        if ((l < n && elementos->at(l)->getCountryName() < elementos->at(largest)->getCountryName())
            || (elementos->at(l)->getCountryName() == elementos->at(largest)->getCountryName() && elementos->at(l)->getYear() < elementos->at(largest)->getYear())
            || (elementos->at(l)->getCountryName() == elementos->at(largest)->getCountryName() && elementos->at(l)->getYear() == elementos->at(largest)->getYear() && elementos->at(l)->getTradeUsd() < elementos->at(largest)->getTradeUsd()))
            largest = l;

        // If right child is larger than largest so far
        if ((r < n && elementos->at(r)->getCountryName() < elementos->at(largest)->getCountryName())
            || (elementos->at(r)->getCountryName() == elementos->at(largest)->getCountryName() && elementos->at(r)->getYear() < elementos->at(largest)->getYear())
            || (elementos->at(r)->getCountryName() == elementos->at(largest)->getCountryName() && elementos->at(r)->getYear() == elementos->at(largest)->getYear() && elementos->at(r)->getTradeUsd() < elementos->at(largest)->getTradeUsd()))
            largest = r;

        // If largest is not root
        if (largest != i) {
            swap(elementos->at(i), elementos->at(largest));

            // Recursively heapify the affected sub-tree
            heapify(n, largest,criterio);
        }
    }
}

// main function to do heap sort
template <class T>
void Sorts<T>::heapSort(string criterio)
{
    if (criterio == "TradeUsd") {
        int n = elementos->size();
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; --i)
            heapify(n, i,criterio);

        // One by one extract an element from heap
        for (int i = n - 1; i >= 0; --i) {
            // Move current root to end
            swap(elementos->at(0), elementos->at(i));

            // call max heapify on the reduced heap
            heapify(i, 0,criterio);
        }
    }
    if (criterio == "Criterio2") {
        int n = elementos->size();
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; --i)
            heapify(n, i,criterio);

        // One by one extract an element from heap
        for (int i = n - 1; i >= 0; --i) {
            // Move current root to end
            swap(elementos->at(0), elementos->at(i));

            // call max heapify on the reduced heap
            heapify(i, 0,criterio);
        }
    }
}

template <class T>
void Sorts<T>::heapSortTradeUsd() {
    heapSort("TradeUsd");
}

template <class T>
void Sorts<T>::heapSortCriterio2() {
    heapSort("Criterio2");
}



//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
// METODOS NECESARIOS PARA EL MERGE-SORT
template <class T>
void Sorts<T>::merge(int left, int mid, int right,string criterio){
    if (criterio == "TradeUsd") {
        int i, j;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<T *> L(n1);
        vector<T *> R(n2);

        for (i = 0; i < n1; ++i) {
            L[i] = elementos->at(left + i);
        }
        for (j = 0; j < n2; ++j) {
            R[j] = elementos->at(mid + 1 + j);
        }

        i = 0;
        j = 0;
        auto it = elementos->begin();
        for (int x = 0; x < left; x++) {
            it++;
        }
        while (i < n1 && j < n2) {
            if (L[i]->getTradeUsd() >= R[j]->getTradeUsd()) {
                elementos->erase(it);
                elementos->insert(it, L[i]);
                i++;
            } else {
                elementos->erase(it);
                elementos->insert(it, R[j]);
                j++;
            }
            it++;
        }

        while (i < n1) {
            elementos->erase(it);
            elementos->insert(it, L[i]);
            i++;
            it++;
        }

        while (j < n2) {
            elementos->erase(it);
            elementos->insert(it, R[j]);
            j++;
            it++;
        }
    }

    if (criterio == "Criterio2"){
        int i, j;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<T *> L(n1);
        vector<T *> R(n2);

        for (i = 0; i < n1; ++i) {
            L[i] = elementos->at(left + i);
        }
        for (j = 0; j < n2; ++j) {
            R[j] = elementos->at(mid + 1 + j);
        }

        i = 0;
        j = 0;
        auto it = elementos->begin();
        for (int x = 0; x < left; x++) {
            it++;
        }
        while (i < n1 && j < n2) {
            if (L[i]->getCountryName() > R[j]->getCountryName()
            || ((L[i]->getCountryName() == R[j]->getCountryName()) && L[i]->getYear() > R[j]->getYear())
            || ((L[i]->getCountryName() == R[j]->getCountryName()) && L[i]->getYear() > R[j]->getYear() && L[i]->getTradeUsd() >= R[j]->getTradeUsd())) {
                elementos->erase(it);
                elementos->insert(it, L[i]);
                i++;
            } else {
                elementos->erase(it);
                elementos->insert(it, R[j]);
                j++;
            }
            it++;
        }

        while (i < n1) {
            elementos->erase(it);
            elementos->insert(it, L[i]);
            i++;
            it++;
        }

        while (j < n2) {
            elementos->erase(it);
            elementos->insert(it, R[j]);
            j++;
            it++;
        }
    }
}

template <class T>
void Sorts<T>::mergeSort(int l, int r,string criterio){
    if (criterio == "TradeUsd") {
        if (l < r) {
            int m = l + (r - l) / 2;

            mergeSort(l, m,criterio);
            mergeSort(m + 1, r,criterio);
            merge(l, m, r,criterio);
        }
    }
    if (criterio == "Criterio2") {
        if (l < r) {
            int m = l + (r - l) / 2;

            mergeSort(l, m,criterio);
            mergeSort(m + 1, r,criterio);
            merge(l, m, r,criterio);
        }
    }
}

template <class T>
void Sorts<T>::mergeSortTradeUsd() {
    mergeSort(0,elementos->size() - 1,"TradeUsd");
}

template <class T>
void Sorts<T>::mergeSortCriterio2() {
    mergeSort(0,elementos->size()-1,"Criterio2");
}

#endif //MINI_P2_SORTS_H
