//
// Created by Wiktoria on 17.12.2020.
//

#include "Blik.h"
#include "readFile.h"

void Blik::pay() const {
    std::string PIN = "0";
    bool compatibility = true, time;
    std::cout << "..........................................\n\t\tBlik\n.........................................."<< std::endl;
    std::cout << "Please provide the following information:" << std::endl;
    do {
        auto start = std::chrono::steady_clock::now();
        std::cout << "Blik code (it is a sequence of 6 digits):" << std::endl;
        PIN = readFile::rString();
        if (PIN.size() == 6) {
            for (char i: PIN)
                if (!isdigit(i)) {
                    compatibility = false;
                    std::cout << "Error, the PIN is not all digits" << std::endl;
                } else compatibility = true;

        } else compatibility = false;
        auto end = std::chrono::steady_clock::now();
        auto intr = std::chrono::duration_cast<std::chrono::seconds>(end - start);
        if (intr.count() >120) {
            std::cout << "time to enter the code has passed. Retry.\n";
            time = false;
        } else time = true;
        std::cout << "_______\nduration time :" << intr.count() << "sec\n_______" << std::endl;
    } while (!compatibility || !time);
    std::cout<< "..........................................\n\t you purchased the product\n.........................................."<< std::endl;

}

