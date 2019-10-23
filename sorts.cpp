#include<iostream>

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

