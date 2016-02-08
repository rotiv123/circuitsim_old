//
// Created by vitor on 04-10-2015.
//

#include <cstring>
#include <algorithm>

#include "matrix.h"


matrix::matrix(unsigned m, unsigned n)
        : m_(m), n_(n), buff_(new double[m * n])
{
    std::memset(this->buff_, 0, sizeof(double) * m * n);
}

matrix::~matrix()
{
    delete[] this->buff_;
}

matrix::matrix(matrix&& o)
        : m_(o.m_), n_(o.n_), buff_(o.buff_)
{
}

matrix& matrix::operator=(matrix&& o)
{
    if (this != &o)
    {
        this->m_ = o.m_;
        this->n_ = o.n_;
        this->buff_ = o.buff_;
    }

    return *this;
}

void matrix::swap_rows(unsigned a, unsigned b)
{
    assert(a < this->m_);
    assert(b < this->m_);

    if (a == b)
    {
        return;
    }

    for (unsigned j = 0; j < this->n_; ++j)
    {
        std::swap(this->at(a, j), this->at(b, j));
    }
}
