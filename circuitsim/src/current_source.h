//
// Created by vitor on 12-07-2015.
//

#ifndef CIRCUITSIM_CURRENT_SOURCE_H
#define CIRCUITSIM_CURRENT_SOURCE_H


#include <string>
#include "token.h"
#include "parser.h"

class current_source
{
public:
    current_source(const token& id, parser& p);

private:
    std::string id_;
    int plus_n_;
    int minus_n_;
    std::string type_;
    double value_;
};

#endif //CIRCUITSIM_CURRENT_SOURCE_H
