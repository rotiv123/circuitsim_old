//
// Created by vitor on 20-08-2015.
//

#ifndef CIRCUITSIM_UTILS_H
#define CIRCUITSIM_UTILS_H

#include <string>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>

#include "matrix.h"

std::string& last_error() noexcept;

template<typename F, typename... Args>
void no_throw(F&& f, Args&& ... args) noexcept
{
    last_error() = "";
    try
    {
        f(std::forward<Args>(args)...);
    }
    catch (const std::exception& e)
    {
        last_error() = e.what();
    }
}

template<typename M>
void dump(const M& mat)
{
    for(unsigned i = 0; i < mat.rows(); ++i)
    {
        std::cout << "[" << std::setw(9) << mat.at(i, 0);
        for(unsigned j = 1; j < mat.cols(); ++j)
        {
            std::cout << ", " << std::setw(9) << mat.at(i, j);
        }

        std::cout << "]" << std::endl;
    }

    std::cout << std::endl;
}

template<typename M>
void reduced_row_echelon(M& mat)
{
    row_echelon(mat);

    //dump(mat);

    for (int k = mat.rows() - 1; k > -1; --k)
    {
        double mkk = mat.at(k, k);
        for (unsigned j = mat.rows(); j < mat.cols(); ++j)
        {
            mat.at(k, j) /= mkk;
        }
        mat.at(k, k) = 1.0;

        for (int i = k - 1; i > -1; --i)
        {
            double mik = mat.at(i, k);
            for (unsigned j = k + 1; j < mat.cols(); ++j)
            {
                mat.at(i, j) -= mat.at(k, j) * mik;
            }
            mat.at(i, k) = 0.0;
        }
    }
}

template<typename M>
void row_echelon(M& mat)
{
    for (unsigned k = 0; k < std::min(mat.rows(), mat.cols()); ++k)
    {
        unsigned i_max = k;
        for (unsigned i = k + 1; i < mat.rows(); ++i)
        {
            double t = std::fabs(mat.at(i, k));
            if(t > std::fabs(mat.at(i_max, k)))
            {
                i_max = i;
            }
        }

        if (mat.at(i_max, k) == 0)
        {
            throw std::logic_error{"matrix is singular!"};
        }

        mat.swap_rows(k, i_max);

        double mkk = mat.at(k, k);

        for (unsigned i = k + 1; i < mat.rows(); ++i)
        {
            double temp = mat.at(i, k) / mkk;
            for (unsigned j = k + 1; j < mat.cols(); ++j)
            {
                mat.at(i, j) -= mat.at(k, j) * temp;
            }
            mat.at(i, k) = 0.0;
        }
    }
}

#endif //CIRCUITSIM_UTILS_H
