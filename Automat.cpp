//
// Created by Wiktoria on 23.11.2020.
//
#include "Automat.h"
#include "Payment.h"
#include "Card.h"
#include "Blik.h"
#include "readFile.h"

Automat::Automat() {

    for (int i = 0; i <SIZE; i++)
    {
        amount[i] = 3;
    }

                                    //initialize a dynamic array of Drink class objects
    drink[0].add(0, "Piwniczanka", 2);
    drink[1].add(1, "ice tea  ", 3.7);
    drink[2].add(2, "Coca Cola", 6.1);
    drink[3].add(3, "Schweppes ", 10);

}

//displaying the content
void Automat::show() {
    std::cout << "|";for (int i = 0; i < 54; i++) { std::cout << "-"; }std::cout << "|" << std::endl;
    std::cout << "|" << "\t\t DRINK   MACHINE\t\t       |" << std::endl;
    std::cout << "|";for (int i = 0; i < 54; i++) { std::cout << "."; }std::cout << "|" << std::endl;
    std::cout << "|" << " available products:\t\t\t\t       |" << std::endl;
    for (int j = 0; j < SIZE; j++) {
        std::cout << "|" << " id " << drink[j].ID << " " << drink[j].name << " price: " << drink[j].price << " zl "<< " quantity available: " << amount[j] << "  " << "|" << std::endl;}std::cout << "|";
    for (int i = 0; i < 54; i++) { std::cout << "_"; }std::cout << "|" << std::endl;
}

int Automat::choose() {
   int chs;
    do {
        try {
            std::cout << "select a product (enter the number of the item where the chosen product is located): "<< std::endl;
             chs = readFile::rInt(3);
            switch (chs) {
                case 0: {
                    if (amount[0] == 0) {
                        std::cout << "product not available, please choose another one\n................." << std::endl;
                        chs = -1;
                        break;
                    } else {
                        std::cout << "the drink with the number " << chs << " has been selected ";
                        std::cout << drink[0].name << std::endl;
                    }
                    break;
                }
                case 1: {
                    if (amount[1] == 0) {
                        std::cout << "product not available, please choose another one\n................." << std::endl;
                        chs = -1;
                        break;
                    } else {
                        std::cout << "the drink with the number " << chs << " has been selected ";
                        std::cout << drink[1].name << std::endl;
                    }
                    break;
                }
                case 2: {
                    if (amount[2] == 0) {
                        std::cout << "product not available, please choose another one\n................." << std::endl;
                        chs = -1;
                        break;
                    } else {
                        std::cout << "the drink with the number " << chs << " has been selected ";
                        std::cout << drink[2].name << std::endl;
                    }
                    break;
                }
                case 3: {
                    if (amount[3] == 0) {
                        std::cout << "product not available, please choose another one\n................." << std::endl;
                        chs = -1;
                        break;
                    } else {
                        std::cout << "the drink with the number " << chs << " has been selected ";
                        std::cout << drink[3].name << std::endl;
                    }
                    break;
                }
            default:
              break;
            }
        }
        catch (Aid &w) {
            std::cout << "____________________\nEXCEPTION:" << w.message << "\n____________________" << std::endl;
            chs = -1;
        }
    } while (3 < chs || chs < 0);
    return chs;
}

void
Automat::nominal() {
    auto *k = new Card;
    auto *b = new Blik;
    bool inTab = false;
    bool ok;          // is responsible for checking if the coin is less than the value to be settled
    int gr, zl, tmp, coin, value, method;
    float price, helper;
    int nom[6]{500, 200, 100, 50, 20, 10};          //values: 5zl, 2zl, 1zl, 50gr, 20 gr, 10gr
    int chs = choose();             //assign the result as returned by the function choice ();
    switch (chs) {
        case 0:
            std::cout << ".................\nyou have to pay 2zl \n................." << std::endl;
            price = drink[0].price;
            break;
        case 1:
            std::cout << ".................\nyou have to pay 3zl 70 gr \n................." << std::endl;
            price = drink[1].price;
            break;
        case 2:
            std::cout << ".................\nyou have to pay 6zl 10 gr \n................." << std::endl;
            price = drink[2].price;
            break;
        case 3:
            std::cout << ".................\nyou have to pay 10 zl \n................." << std::endl;
            price = drink[3].price;
            break;
        default:
            break;

    }
    try {
        std::cout << "Please select the type of transaction (number): \n 1.in cash\n2.by card\n3.Blik" << std::endl;
        method = readFile::rInt();// use the range operator to use the appropriate method of the class read to input data
        std::cout << "_____________________________________" << std::endl;
        switch (method) {
            case 1:
                value = static_cast<int>(price) * 100;
                std::cout << " The machine accepts only the following values:\n\t 5zl, 2zl, 1zl, 50gr, 20gr,10gr\n"
                             " Any other coins will not be accepted, the machine will not return the change." << std::endl;
                do
                {
                    do {

                       std::cout << "\n Enter a coin: " << std::endl;
                        helper = readFile::rfloat(3.2);
                        if (helper!=10 && helper!=20 && helper!=50 && helper!=1 &&helper!=2 && helper!=5) {
                            std::cout << "error, write the value in the following form: 2zl ==2 , 50gr==50, 20gr==20 etc. "<< std::endl;
                            coin = 0;
                        } else coin = static_cast<int>(helper);
                        if (coin > 0 && coin < 6) coin = coin * 100;

                        for (int i = 0; !inTab && i < 6; ++i)
                        {
                            inTab = (nom[i] == coin);
                        }

                        if (inTab) std::cout << "value recognized" << std::endl;
                        else {
                            std::cout << "The given value was not recognized, Please enter a coin from the allowed values"<< std::endl;
                            inTab= false;
                        }
                    } while (!inTab);
                    inTab = false;
                    if (coin > 0 && coin < 6) { coin *= 100; }
                    for (int i : nom) {
                        if (i == coin) {
                            ok = (i <=value);
                            if (ok) {
                                value= value - i;
                                if (value >=100) {
                                    tmp = value / 100;
                                    zl = tmp;
                                    gr = value - (tmp * 100);
                                    std::cout << "Left to pay: " << zl << " zl " << gr << " gr" << std::endl;
                                } else std::cout << "Left to pay: " << value << " gr" << std::endl;
                            } else std::cout << "error, enter a smaller value than the rest." << std::endl;
                        }
                    }
                } while (!check(value));
                amount[chs]--;
                break;
            case 2:
                k->pay();
                amount[chs]--;
                break;
            case 3:
                b->pay();
                amount[chs]--;
                break;
           default:
                break;
        }
    }
    catch (Apayment &m) {
        std::cout << "____________________\nException:" << m.message << "\n____________________" << std::endl;
    }
    delete b;
    delete k;

}

bool Automat::check(int &i) {
    if (i == 0) {
        std::cout << ".................\nYou have purchased a product\n................." << std::endl;
        return true;
    } else
        return false;
}

bool Automat::isEmpty()  {
    bool tmp = false;
    for (int j = 0; j < SIZE; j++) {
        if (amount[j] == 0) tmp = true;
        else return false;
    }
    return tmp;
}

Automat::~Automat() {
    std::cout << "________________________\n the program has ended" << std::endl;
}
