//
// Created by vitor on 04-10-2015.
//

#ifndef CIRCUITSIM_MATRIX_H
#define CIRCUITSIM_MATRIX_H

#include <cassert>


class matrix final
{
public:

    matrix(unsigned m, unsigned n);
    matrix(const matrix&) =delete;
    matrix(matrix&& other);

    ~matrix();

    matrix& operator=(const matrix&) =delete;
    matrix& operator=(matrix&& other);

    unsigned cols() const
    {
        return this->n_;
    }

    unsigned rows() const
    {
        return this->m_;
    }

    double at(unsigned i, unsigned j) const
    {
        assert(i < this->m_);
        assert(j < this->n_);

        return this->buff_[this->n_ * i + j];
    }

    double& at(unsigned i, unsigned j)
    {
        assert(i < this->m_);
        assert(j < this->n_);

        return this->buff_[this->n_ * i + j];
    }

    void swap_rows(unsigned a, unsigned b);

private:
    unsigned m_, n_;
    double* buff_;
};

#endif //CIRCUITSIM_MATRIX_H
