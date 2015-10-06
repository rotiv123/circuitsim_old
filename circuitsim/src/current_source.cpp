//
// Created by vitor on 12-07-2015.
//

#include "current_source.h"

current_source::current_source(const token& id, parser& p)
        : id_{to_string(id)},
          plus_n_{(unsigned) std::stoi(to_string(p.advance()))},
          minus_n_{(unsigned) std::stoi(to_string(p.advance()))},
          type_{to_string(p.advance())},
          value_{std::stod(to_string(p.advance()))}
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
