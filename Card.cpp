//
// Created by Wiktoria on 17.12.2020.
//

#include "Card.h"
#include "readFile.h"

void Card::pay() const {
    std::string PIN = "0";
    bool compatibility = true;
    std::cout<< "..........................................\n\tCredit card\n.........................................."<< std::endl;
    std::cout << "Please provide the following information:" << std::endl;

    do {
        std::cout << "PIN number (it is a sequence of 4 digits):" << std::endl;
        PIN = readFile::rString();
        if (PIN.size() == 4) {
            for (char i: PIN)
                if (!isdigit(i)) {
                    compatibility = false;
                    std::cout << "Error, the PIN is not all digits" << std::endl;
                } else compatibility = true;

        } else compatibility = false;
    } while (!compatibility);

    std::cout<< "..........................................\n\t you purchased the product\n.........................................."<< std::endl;
}
