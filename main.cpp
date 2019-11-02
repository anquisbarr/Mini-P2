#include "sorts.h"
#include "sorts.cpp"
#include "sumarizar.h"
#include <ctime>


int main(){
    unsigned t0,t1,t2,t3;
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

    //sort->mostrarElementos();
    cout<<"Tiempo de ejecucion de cada sort segun el primer criterio:"<<endl;
    //sort->listarCountries();
    cout<< "Tiempo de ejecucion del Quicksort: ";
    t0=clock();
    sort->QuickSort(0, sort->size()-1);
    t1=clock();
    double time_1 =((t1-t0)/1000.0);
    sort->listarCountries(1);
    cout<<time_1<<endl;
    cout<< "Tiempo de ejecucion del Shellsort: ";
    t1=clock();
    sort->ShellSort();
    t2=clock();
    double time_2 =((t2-t1)/1000.0);
    cout<<time_2<<endl;
    sort->listarCountries(2);
    t2=clock();
    sort->heapSort();
    t3=clock();


    /*auto* sumarizacion = new Sumarizar<Country>("commodity_trade_statistics_data.csv");

    sumarizacion->sumarizacion1();
    sumarizacion->listarResult1();
    sumarizacion->sumarizacion2();
    sumarizacion->listarResult2();

    delete sumarizacion;

    return 0;*/
}