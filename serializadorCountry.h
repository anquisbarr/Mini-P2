//
// Created by Sebastian Q.B on 30/10/2019.
//

#ifndef MINI_P2_SERIALIZADORCOUNTRY_H
#define MINI_P2_SERIALIZADORCOUNTRY_H

#include "serializador.h"
#include "Country.h"
#include <sstream>

template <class T>
class serializadorCountry:public Serializador<Country>{
public:
    serializadorCountry();
    ~serializadorCountry();
    string Serializar(T*,string) override;
};

template <class T>
serializadorCountry<T>::serializadorCountry():Serializador(){}

template <class T>
serializadorCountry<T>::~serializadorCountry() {}

template <class T>
string serializadorCountry<T>::Serializar(T *country, string delim) {
    return  country->getCountryName()+ delim+
            to_string(country->getYear()) + delim +
            to_string(country->getCommCode())+ delim +
            country->getCommodity() + delim +
            country->getFlow() + delim +
            to_string(country->getTradeUsd) + delim +
            country->getWeight() + delim +
            country->getQuantityName() + delim +
            country->getQuantity() + delim +
            country->getCategory();
}
#endif //MINI_P2_SERIALIZADORCOUNTRY_H
