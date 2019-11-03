#include "sorts.h"
#include "sorts.cpp"
#include "sumarizar.h"
#include <ctime>


int main(){

    auto* sort = new Sorts<Country>("sample_data.csv");

    /*//sort->mostrarElementos();
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
    t3=clock();*/

    sort->heapSortCriterio2();
    sort->listarCountries(7);


    /*auto* sumarizacion = new Sumarizar<Country>("commodity_trade_statistics_data.csv");

    sumarizacion->sumarizacion1();
    sumarizacion->listarResult1();
    sumarizacion->sumarizacion2();
    sumarizacion->listarResult2();

    delete sumarizacion;

    return 0;*/
}