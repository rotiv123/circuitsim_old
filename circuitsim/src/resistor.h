//
// Created by vitor on 05-07-2015.
//

#ifndef CIRCUITSIM_RESISTOR_H
#define CIRCUITSIM_RESISTOR_H

#include <string>
#include "token.h"
#include "parser.h"

class resistor final
{
public:
    resistor(const token& id, parser& p);

private:
    std::string id_;
    int n1_;
    int n2_;
    double value_;
};


#endif //CIRCUITSIM_RESISTOR_H
