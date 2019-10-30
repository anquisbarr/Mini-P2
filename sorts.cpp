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
void merge(vector<S>* vect){
    if (vect > 1) {
        int mid = vect->size()/2;

        vector<S> *L = new vector<S>();
        vector<S> *R = new vector<S>();

        for (S v : *vect){
            if (vect->size() < mid)
                L->push_back(v);
            else
                R->push_back(v);
        }

        merge(*L);
        merge(*R);
        mergeSort();
    }
}

template <class T>
void mergeSort(vector<T>* left,vector<T>* right,vector<T>* nuevoVector){
    unsigned int nl = left->size();
    unsigned int nr = right.size();
    unsigned int i = 0, j = 0, k = 0;

    auto i1 = left->begin();
    auto i2 = right->begin();

    while (j < nl && k < nr){
        if (*i1 < *i2){
            nuevoVector->push_back(*i1);
            i1++;
            j++;
        }
        else{
            nuevoVector->push_back(*i2);
            i2++;
            k++;
        }
        i++;
    }

    while(j<nl){
        nuevoVector->push_back(*i1);
    }

    while (k<nr){
        nuevoVector->push_back(*i2);
    }
}

