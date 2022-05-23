//
// Created by Wiktoria on 08.01.2021.
//

#ifndef DROZDZWIKTORIA_CONTAINER_H
#define DROZDZWIKTORIA_CONTAINER_H
#include <stdexcept>
#include "Exception.h"

template<typename T, size_t size>
class Container {
    T *amount = nullptr;             //deklaracja wskaznika
   // size_t pojemnosc = 128;
    //int rozm=128;                                 //zakomentowalam zmienne/metody, aby nie wyswietlalo sie ostrzezenie, ze te funkcje nie sa uzywane
public:
    Container();

    T &operator[](int i);

    //void dodaj(const T &obiekt);

   // int roz() const;

    ~Container();    //destruktor-> zwalnianie pamieci
};


template<typename T, size_t size>
Container<T, size>::Container() {          //deklaracje tablicy dynamiczne-> kontenera
    //pojemnosc=rozm;
    amount = new T[size];
}

template<typename T, size_t size>                //sprawdzanie poprawnosc indeksu oraz zwracanie elementu tablicy
T &Container<T, size>::operator[](int i) {
    if (i < 0 || i >= size)
        throw std::invalid_argument("Podano bledny wymiar tablicy. Awaryjne wylaczenie automatu.");  //przy niepoprawnym rozmiarze pamieci zostanie rzucony wyjatek o nieprawnie podanym argumencie i program zostanie zakonczony w trybie awaryjnym z kodem wyjscia 3
    return amount[i];
}

/*
template<typename T, size_t rozmiar>
void Kontener<T, rozmiar>::dodaj(const T &obiekt) {
    if (this->rozmiar < this->pojemnosc) this->ilosc[this->ozmiar++] = obiekt;
    else std::cout << "tablica jest zapelniona" << std::endl;
}

template<typename T, size_t rozmiar>
int Kontener<T, rozmiar>::roz() const {
    return rozmiar;
}
*/
template<typename T, size_t size>
Container<T, size>::~Container() {     //usuniecie (zwolnienie) tablicy->kontenera
    delete[]amount;
}

#endif //DROZDZWIKTORIA_EXCEPTION

