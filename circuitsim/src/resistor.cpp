//
// Created by vitor on 05-07-2015.
//

#include "resistor.h"


resistor::resistor(const token& id, parser& p)
    : id_{},
      n1_{0},
      n2_{0},
      value_{0.0}
{
    id_ = to_string(id);
    n1_ = (unsigned) std::stoi(to_string(p.advance()));
    n2_ = (unsigned) std::stoi(to_string(p.advance()));
    value_ = std::stod(to_string(p.advance()));
}

void resistor::stamp(matrix& mat, unsigned) const
{
    if (this->n1_ > 0 && this->n2_ > 0)
    {
        mat.at(this->n1_ - 1, this->n1_ - 1) += 1.0 / this->value_;
        mat.at(this->n2_ - 1, this->n2_ - 1) += 1.0 / this->value_;

        mat.at(this->n1_ - 1, this->n2_ - 1) += -1.0 / this->value_;
        mat.at(this->n2_ - 1, this->n1_ - 1) += -1.0 / this->value_;
    }
    else if (this->n1_ > 0)
    {
        mat.at(this->n1_ - 1, this->n1_ - 1) += 1.0 / this->value_;
    }
    else if (this->n2_ > 0)
    {
        mat.at(this->n2_ - 1, this->n2_ - 1) += 1.0 / this->value_;
    }
}
