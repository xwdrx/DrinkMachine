//
// Created by Wiktoria on 17.12.2020.
//

#ifndef DROZDZWIKTORIA_PAYMENT_H
#define DROZDZWIKTORIA_PAYMENT_H

#include <iostream>
#include "Automat.h"

class Payment {
public:

    Payment() = default;
    virtual void pay() const {};
    virtual ~Payment() = default;


};

#endif //DROZDZWIKTORIA_PAYMENT_H
