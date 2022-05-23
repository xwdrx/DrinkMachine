//
// Created by Wiktoria on 23.11.2020.
//

#ifndef DROZDZWIKTORIA_AUTOMAT_H
#define DROZDZWIKTORIA_AUTOMAT_H

#include "Drink.h"
#include "Container.h"

constexpr int SIZE = 4;       //global constant used to determine the size of the array

class Automat {
private:
    Container<int, SIZE> amount;
    Container<Drink, SIZE> drink;

public:
    Automat();      //constructor
    void show();           //method responsible for displaying
    int choose();           // the method responsible for retrieving the product selection from the user
    void nominal();          // the method responsible for the payment of receivables
    static bool check(int &i);     //the method responsible for checking whether the payment has been settled
    bool isEmpty();                 //checks if the machine is empty
    ~Automat();

};

#endif //DROZDZWIKTORIA_AUTOMAT_H
