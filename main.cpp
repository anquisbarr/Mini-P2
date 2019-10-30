#include "Country.cpp"
#include "sorts.cpp"


int main(){
    //Countries *p= new Countries("sample_data.csv");
    //p->mostrar_countries();
    //delete p;

    vector<int>* enteros = new vector<int>();
    vector<int>* temp = new vector<int>();
    enteros->push_back(3);
    enteros->push_back(6);
    enteros->push_back(1);
    enteros->push_back(4);
    enteros->push_back(7);
    enteros->push_back(2);


    for (int x : *enteros){
        cout << x << endl;
    }

    merge(enteros);

    cout << endl << endl;

    for (int y : *enteros){
        cout << y << endl;
    }



    return 0;
}