#include "sorts.h"
#include "sorts.cpp"
#include <ctime>

int main(){
    unsigned t0,t1;
    //Countries *p= new Countries("sample_data.csv");
    //p->mostrar_countries();
    //delete p;

    /*vector<int>* enteros = new vector<int>();
    vector<int>* temp = new vector<int>();
    enteros->push_back(3);
    enteros->push_back(6);
    enteros->push_back(1);
    enteros->push_back(4);
    enteros->push_back(7);
    enteros->push_back(2);
    enteros->push_back(5);


    for (int x : *enteros){
        cout << x << "," ;
    }

    shell(enteros);

    cout << endl << endl;

    for (int y : *enteros){
        cout << y <<", ";
    }*/

    auto* sort = new Sorts<Country>("sample_data.csv");

    sort->mostrarElementos();
    t0=clock();
    sort->QuickSort(0, sort->size()-1);
    t1=clock();


    double time_1 =((t1-t0)/1000.0);

    sort->listarCountries();

    cout<< "Execution time off Quicksort: "<<time_1;

    return 0;
}