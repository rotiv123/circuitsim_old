//
// Created by vitor on 12-07-2015.
//

#ifndef CIRCUITSIM_VOLTAGE_SOURCE_H
#define CIRCUITSIM_VOLTAGE_SOURCE_H


#include <string>

#include "matrix.h"
#include "token.h"
#include "parser.h"

class voltage_source
{
public:
    voltage_source(const token& id, parser& p, unsigned ith);

    unsigned max_node() const
    {
        return std::max(this->plus_n_, this->minus_n_);
    }

    void stamp(matrix& mat, unsigned n) const;

private:
    std::string id_;
    unsigned plus_n_;
    unsigned minus_n_;
    std::string type_;
    double value_;
    unsigned ith_;
};

#endif //CIRCUITSIM_VOLTAGE_SOURCE_H
