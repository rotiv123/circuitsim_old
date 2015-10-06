//
// Created by vitor on 12-07-2015.
//

#include "voltage_source.h"

voltage_source::voltage_source(const token& id, parser& p, unsigned ith)
    : id_{},
      plus_n_{0},
      minus_n_{0},
      type_{},
      value_{0.0},
      ith_{ith}
{
    id_ = to_string(id);
    plus_n_ = (unsigned) std::stoi(to_string(p.advance()));
    minus_n_ = (unsigned) std::stoi(to_string(p.advance()));
    type_ = to_string(p.advance());
    value_ = std::stod(to_string(p.advance()));
}


void voltage_source::stamp(matrix& mat, unsigned n) const
{
    unsigned col = mat.cols() - 1;

    if (this->plus_n_ > 0)
    {
        mat.at(this->plus_n_ - 1, n + this->ith_) = 1.0;
        mat.at(n + this->ith_, this->plus_n_ - 1) = 1.0;

        mat.at(n + this->ith_, col) += this->value_;
    }

    if (this->minus_n_ > 0)
    {
        mat.at(this->minus_n_ - 1, n + this->ith_) = -1.0;
        mat.at(n + this->ith_, this->minus_n_ - 1) = -1.0;

        mat.at(n + this->ith_, col) -= this->value_;
    }
}
