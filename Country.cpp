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
        }
        if (spaces.size()==10)
            string countryName = spaces[0];
            unsigned int year = stoi(spaces[1]);
            unsigned int commCode = stoi(spaces[2]);
            string commodity = spaces[3];
            string flow = spaces[4];
            unsigned int trade_usd = stoi(spaces[5]);
            unsigned int weight = stoi(spaces[6]);
            string quantity_name = spaces[7];
            unsigned int quantity = stoi(spaces[8]);
            string category = spaces[9];
        }

};

