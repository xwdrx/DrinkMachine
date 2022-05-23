//
// Created by Wiktoria on 17.12.2020.
//

#ifndef DROZDZWIKTORIA_CARD_H
#define DROZDZWIKTORIA_CARD_H

#include <iostream>
#include <string>
#include "Payment.h"

class Card : public Payment {
public:
    Card() = default;

    void pay() const override;

    ~Card() override = default;
};

#endif //DROZDZWIKTORIA_CARD_H
