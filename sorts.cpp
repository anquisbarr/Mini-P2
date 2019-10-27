#include<iostream>
#include "Country.cpp"

using namespace std;


template<class T,class S>
void quick_sort(Countries* a,int i,int d){
    vector<S>* v1 = a->get_countries();
    int izquierda=v1->begin();
    int derecha=v1->size()-1;
    T temp;
    T pivot=v1[v1->begin/2]->getTradeUsd();
    while(izquierda <= derecha){
        while(v1[izquierda]<pivot){
            izquierda++;
        }
        while(v1[derecha]>pivot){
            derecha--;
        }
        if(izquierda <= derecha){
            temp=v1[izquierda]->getTradeUsd();
            izquierda=v1[derecha]->getTradeUsd();
            derecha=temp;
        }
    }
    a->set_countries(v1);
    if(i<derecha){
        quick_sort(a,i,derecha);
        if(izquierda<d){
            quick_sort(a,izquierda,d);
        }
    }
    
}


template <class S>
void merge(vector<S> *vect,int l,int m,int r){
    int count = 0;
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<S>* L = new vector<S>();
    vector<S>* R = new vector<S>();

    for (S palabra : *vect){
        if (count < n1)
            L->push_back(palabra);
        else
            R->push_back(palabra);
        count++;
    }

    int i = 0, j = 0, k= l;
    while(i<n1 && j < n2){
        if (*L[i] <= *R[j]){
            *vect[k] = *L[i];
            i++;
        }
        else{
            *vect[k] = *R[j];
            j++;
        }
        k++;
    }
}

template <class T>
void mergeSort(T lista){

}

