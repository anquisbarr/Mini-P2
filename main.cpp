#include "Country.cpp"
#include "sorts.cpp"


int main(){
    /*Countries *p= new Countries("prueba.txt");
    p->mostrar_countries();
    delete p;*/

    vector<int>* enteros = new vector<int>();
    vector<int>* temp = new vector<int>();
    enteros->push_back(3);
    enteros->push_back(6);
    enteros->push_back(1);
    enteros->push_back(4);

    merge(enteros,temp);

    for (int x : *enteros){
        cout << x << endl;
    }
    cout << endl << endl;

    for (int y : *temp){
        cout << y << endl;
    }



    return 0;
}