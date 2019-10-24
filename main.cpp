#include <iostream>
//
// Created by Sebastian Q.B on 10/19/2019.
//
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <forward_list>
#include <vector>

using namespace std;

class Country{
private:
    string countryName;
    unsigned int year;
    unsigned int commCode;
    string commodity;
    string flow;
    unsigned int trade_usd;
    unsigned int weight;
    string quantity_name;
    unsigned int quantity;
    string category;
public:
    Country(const string &countryName, unsigned int year, unsigned int commCode, const string &commodity,
            const string &flow, unsigned int tradeUsd, unsigned int weight, const string &quantityName,
            unsigned int quantity, const string &category) : countryName(countryName), year(year), commCode(commCode),
                                                             commodity(commodity), flow(flow), trade_usd(tradeUsd),
                                                             weight(weight), quantity_name(quantityName),
                                                             quantity(quantity), category(category) {}

    const string &getCountryName() const {
        return countryName;
    }

    unsigned int getYear() const {
        return year;
    }

    unsigned int getCommCode() const {
        return commCode;
    }

    const string &getCommodity() const {
        return commodity;
    }

    const string &getFlow() const {
        return flow;
    }

    unsigned int getTradeUsd() const {
        return trade_usd;
    }

    unsigned int getWeight() const {
        return weight;
    }

    const string &getQuantityName() const {
        return quantity_name;
    }

    unsigned int getQuantity() const {
        return quantity;
    }

    const string &getCategory() const {
        return category;
    }

};


class Countries{
private:
    vector<Country*>* countries;

    Country* createCountry(string countryInfo){
        vector<string> spaces;
        stringstream stream(countryInfo);
        string space;
        while(getline(stream,space,',')){
            spaces.push_back(space);
            cout<<space<<endl;
        }
        if (spaces.size()==10){
            string countryName = spaces[0];
            unsigned int year = stoi(spaces[1]);
            unsigned int commCode = stoi(spaces[2]);
            string comodity = spaces[3];
            string flow = spaces[4];
            unsigned int 
            trade_usd = stoi(spaces[5]);
            unsigned int weight = stoi(spaces[6]);
            string quantity_name = spaces[7];
            unsigned int quantity = stoi(spaces[8]);
            string category = spaces[9];

            return new Country(countryName,year,commCode,comodity,flow,trade_usd,weight,quantity_name,quantity,category);


        }   
    }
public:
    Countries(string nom_archivo){
        countries = new vector<Country*>();
        fstream* arch=new fstream(nom_archivo,ios_base::in);
        string linea;
        if(arch){
            while(getline(*arch,linea)){
                Country* f_country= createCountry(linea); 
            }
        } 
        arch->close();
    }
    vector<Country*>* get_countries(){
        return countries;
    }
    vector<Country*>* set_countries(vector<Country*>* f){
        countries=f;
    }
    void mostrar_countries(){
        for(Country* f_country: *countries){
            cout<<f_country->getCountryName()<<","<<f_country->getYear()<<","<<f_country->getCommCode()<<","<<f_country->getCommodity()<<","<<f_country->getFlow()<<","<<f_country->getTradeUsd()<<","<<f_country->getWeight()<<","<<f_country->getQuantityName()<<","<<f_country->getQuantity()<<","<<f_country->getCategory()<<endl;
        }
    }
};

/*
void quick_sorter(){

}

template<class T,class S>
void quick_sorter(Countries* a,int i,int d){
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
        quick_sorter(a,i,derecha);
        if(izquierda<d){
            quick_sorter(a,izquierda,d);
        }
    }   
}

*/


int main(){
    Countries *p=new Countries("prueba.csv");
    p->mostrar_countries();



    return 0;
}