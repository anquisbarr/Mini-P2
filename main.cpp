#include "Country.cpp"


int main(){
    Countries *p= new Countries("prueba.txt");
    p->mostrar_countries();
    delete p;

    return 0;
}