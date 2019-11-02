#include<iostream>
#include<vector>
#include "sorts.h"
using namespace std;

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


  

template<class T>
void Sorts<T>::HeapSort(int size){
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(size, i);

      // Extrae uno por uno cada elemento del heap
      for (int i = size-1; i >= 0; --i)
      {
          // Mueve la raíz actual al final
          std::swap(elementos[0], elementos[i]);

          // Llama a max heapify en el heap reducido
          heapify(i, 0);
      }
}








/*
template <class T>
void mergeSort(vector<T>* left,vector<T>* right,vector<T>* vect){
    unsigned int nl = left->size();
    unsigned int nr = right->size();
    unsigned int j = 0, k = 0;

    auto i1 = left->begin();
    auto i2 = right->begin();
    auto i = vect->begin();

    while (j < nl && k < nr){
        if (*i1 > *i2){
            vect->erase(i);
            vect->insert(i,*i1);
            i1++;
            j++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        a[k] = R[j];
        j++;
        k++;
    }

    delete[] R;
    delete[] L;
}

template<typename T>
void Sorts<T>::mergeSort(T*a, int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}



/*
template <class T>
void swap(vector<T>* vect,int x,int y){
    if (x == y)
        return;

    auto l = vect->begin();
    auto m = vect->begin();

    for (int a = x; a > 0;a--){
        l++;
    }

    for (int b = y; b > 0; b--){
        m++;
    }

    auto temp1 = *l;
    auto temp2 = *m;

    vect->erase(l);
    vect->insert(l,temp2);
    vect->erase(m);
    vect->insert(m,temp1);
}

template <class C>
void sift(vector<C>* vect,int vectSize,int y){
    int m, l;
    l = y;
    auto posVect1 = vect->begin();
    for (int x = l; x > 0; x--){
        posVect1++;
    }

    do{
        m = l;
        auto posVect2 = vect->begin();
        for (int x = m*2 + 1; x > 0; x--){
            posVect2++;
        }

        auto posVect3 = vect->begin();
        for (int x = m*2 + 2;x > 0; x--){
            posVect3++;
        }

        if ((2*m + 1) < vectSize && *posVect1 > *posVect2){
            l = 2*m + 1;
        }

        if ((2*m + 2) < vectSize && *posVect1 > *posVect3){
            l = 2*m + 2;
        }

        swap(vect,m,l);

    }while(m != l);
}



template <class A>
void makeInitialHeap(vector<A>* vect){
    for (int i = vect->size() - 1; i >= 0; --i){
        sift(vect,vect->size(),i);
    }
}

template <class E>
void heap(vector<E>* vect){
    makeInitialHeap(vect);

    for (unsigned int x = vect->size() - 1; x > 0; --x){
        swap(vect,x,0);
        sift(vect,x,0);
    }
}

template <class F>
void shell(vector<F>* vect){
    int tamano = vect->size();
    for (int tam = tamano/2; tam > 0; tam = tam / 2){

        for (int i = tam; i < tamano; i++){

            int itam = i - tam;
            auto pos = vect->begin();
            auto pos2 = vect->begin();
            for (int m = 0; m<i;m++){
                pos++;
            }

            for (int m = 0; m<itam;m++){
                pos2++;
            }
            int temp = *pos;
            int temp2 = *pos2;
            auto temporal1 = vect->begin();
            auto temporal2 = vect->begin();

            for (int j = i; j >=tam && *pos2 > temp; j = j - tam){
                int jj = j - tam;
                pos2 = vect->begin();
                temporal1 = vect->begin();
                temporal2 = vect->begin();
                for (int z = 0; z < jj; z++){
                    pos2++;
                }
                for (int x = 0; x < j; x++){
                    temporal1++;
                }

                for (int y = 0; y < (j-tam); y++){
                    temporal2++;
                }
                vect->erase(temporal1);
                vect->insert(temporal1,*temporal2);
            }
            vect->erase(temporal1);
            vect->insert(temporal1,temp);
        }
    }

}
*/