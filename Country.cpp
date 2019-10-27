#include <iostream>
//
// Created by Sebastian Q.B on 10/19/2019.
//
#include <sstream>
#include <string>
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
    vector<string>* country1;
    vector<unsigned int>* country2;
    vector<unsigned int>* country3;
    vector<string>* country4;
    vector<string>* country5;
    vector<unsigned int>* country6;
    vector<unsigned int>* country7;
    vector<string>* country8;
    vector<unsigned int>* country9;
    vector<string>* country10;

    Country* createCountry(string countryInfo){
        vector<string> spaces;
        stringstream stream(countryInfo);
        string space;
        while(getline(stream,space,',')){
            spaces.push_back(space);
            //cout<<space<<endl;
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
        throw logic_error("No se completaron los 10 atributos");
    }


public:
    Countries(string nom_archivo){
        countries = new vector<Country*>();
        fstream* arch=new fstream(nom_archivo,ios_base::in);
        string linea;
        if(arch){
            while(getline(*arch,linea)){
                Country* f_country= createCountry(linea);
                countries->push_back(f_country);
            }
        }
        arch->close();
        setDatos();
    }

    void setDatos(){
        country1 = new vector<string>();
        country2 = new vector<unsigned int>();
        country3 = new vector<unsigned int>();
        country4 = new vector<string>();
        country5 = new vector<string>();
        country6 = new vector<unsigned int>();
        country7 = new vector<unsigned int>();
        country8 = new vector<string>();
        country9 = new vector<unsigned int>();
        country10 = new vector<string>();
        for (Country* f_countries : *countries){
            country1->push_back(f_countries->getCountryName());
            country2->push_back(f_countries->getYear());
            country3->push_back(f_countries->getCommCode());
            country4->push_back(f_countries->getCommodity());
            country5->push_back(f_countries->getFlow());
            country6->push_back(f_countries->getTradeUsd());
            country7->push_back(f_countries->getWeight());
            country8->push_back(f_countries->getQuantityName());
            country9->push_back(f_countries->getQuantity());
            country10->push_back(f_countries->getCategory());
        }
    }
    vector<Country*>* get_countries(){
        return countries;
    }

    vector<Country*>* set_countries(vector<Country*>* f){
        countries=f;
    }

    vector<string> *getCountry1() const {
        return country1;
    }

    void mostrar_country1(){
        for (string palabra : *country1){
            cout << palabra;
        }
    }

    void mostrar_countries(){
        for(Country* f_country: *countries){
            cout<<f_country->getCountryName()<<","<<f_country->getYear()<<","<<f_country->getCommCode()<<","<<f_country->getCommodity()<<","<<f_country->getFlow()<<","<<f_country->getTradeUsd()<<","<<f_country->getWeight()<<","<<f_country->getQuantityName()<<","<<f_country->getQuantity()<<","<<f_country->getCategory()<<endl;
        }
    }

};
