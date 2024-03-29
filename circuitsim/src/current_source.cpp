//
// Created by vitor on 12-07-2015.
//

#include <cstdlib>

#include "current_source.h"

current_source::current_source(const token& id, parser& p)
        : id_{to_string(id)},
          plus_n_{(unsigned) std::atoi(to_string(p.advance()).c_str())},
          minus_n_{(unsigned) std::atoi(to_string(p.advance()).c_str())},
          type_{to_string(p.advance())},
          value_{std::atof(to_string(p.advance()).c_str())}
{
}

void current_source::stamp(matrix& mat, unsigned) const
{
    unsigned col = mat.cols() - 1;

    if (this->plus_n_ > 0)
    {
        mat.at(this->plus_n_ - 1, col) += this->value_;
    }

    if (this->minus_n_ > 0)
    {
        mat.at(this->minus_n_ - 1, col) -= this->value_;
    }
}
