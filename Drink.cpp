//
// Created by Wiktoria on 23.11.2020.
//

#include "Drink.h"



Drink::Drink(int id, std::string n, float p) : ID(id), name(std::move(n)), price(p) {
}

void Drink::add(int id, std::string n, float c) {
    ID = id;
    name = std::move(n);
    price = c;

}
