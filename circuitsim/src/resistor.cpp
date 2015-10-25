//
// Created by vitor on 05-07-2015.
//

#include <cstdlib>

#include "resistor.h"


resistor::resistor(const token& id, parser& p)
    : id_{},
      n1_{0},
      n2_{0},
      value_{0.0}
{
    id_ = to_string(id);
    n1_ = (unsigned) std::atoi(to_string(p.advance()).c_str());
    n2_ = (unsigned) std::atoi(to_string(p.advance()).c_str());
    value_ = std::atof(to_string(p.advance()).c_str());
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
