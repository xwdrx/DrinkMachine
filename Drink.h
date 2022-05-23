//
// Created by Wiktoria on 23.11.2020.
//

#ifndef PROJEKCIK_NAPOJ_H
#define PROJEKCIK_NAPOJ_H

#include <iostream>
#include <string>

class Drink {
    friend class Automat;
private:
    int ID;
    std::string name;
    float price;
public:
    explicit Drink(int id = -1, std::string n = "...", float c = 0.0);
    void add(int id, std::string n, float c);
    ~Drink()= default;;

};

#endif //
