//
// Created by vitor on 05-07-2015.
//

#ifndef CIRCUITSIM_RESISTOR_H
#define CIRCUITSIM_RESISTOR_H

#include <string>
#include <algorithm>

#include "matrix.h"
#include "token.h"
#include "parser.h"

class resistor final
{
public:
    resistor(const token& id, parser& p);

    unsigned max_node() const
    {
        return std::max(this->n1_, this->n2_);
    }

    void stamp(matrix& mat, unsigned) const;

private:
    std::string id_;
    unsigned n1_;
    unsigned n2_;
    double value_;
};


#endif //CIRCUITSIM_RESISTOR_H
