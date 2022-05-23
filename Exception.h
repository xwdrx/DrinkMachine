//
// Created by Wiktoria on 08.01.2021.
//

#ifndef DROZDZWIKTORIA_EXCEPTION
#define DROZDZWIKTORIA_EXCEPTION

struct AutomatException {                               //dedicated class with error handling
    std::string message;
    explicit AutomatException(std::string w) : message(std::move(w)) {}
};

struct Aid : public AutomatException {
    explicit Aid() : AutomatException("error, there is no such product with such number .") {};
};

struct Apayment : public AutomatException {
    explicit Apayment() : AutomatException("no payment method was selected, transaction canceled") {};
};

#endif
