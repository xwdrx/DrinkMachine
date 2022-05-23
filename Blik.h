//
// Created by Wiktoria on 17.12.2020.
//

#ifndef DROZDZWIKTORIA_BLIK_H
#define DROZDZWIKTORIA_BLIK_H

#include "Payment.h"
#include <chrono>

class Blik : public Payment {
public:
    Blik()= default;
    void pay() const override;
    ~Blik() override = default;
};

#endif //DROZDZWIKTORIA_BLIK_H
