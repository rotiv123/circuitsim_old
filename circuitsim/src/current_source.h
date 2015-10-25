//
// Created by vitor on 12-07-2015.
//

#ifndef CIRCUITSIM_CURRENT_SOURCE_H
#define CIRCUITSIM_CURRENT_SOURCE_H


#include <string>
#include <algorithm>

#include "matrix.h"
#include "token.h"
#include "parser.h"

class current_source
{
public:
    current_source(const token& id, parser& p);

    unsigned max_node() const
    {
        return std::max(this->plus_n_, this->minus_n_);
    }

    void stamp(matrix& mat, unsigned) const;

private:
    std::string id_;
    unsigned plus_n_;
    unsigned minus_n_;
    std::string type_;
    double value_;
};

#endif //CIRCUITSIM_CURRENT_SOURCE_H
