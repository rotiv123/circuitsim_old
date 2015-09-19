//
// Created by vitor on 20-08-2015.
//

#ifndef CIRCUITSIM_UTILS_H
#define CIRCUITSIM_UTILS_H

#include <string>
#include <stdexcept>
#include <utility>

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

#endif //CIRCUITSIM_UTILS_H
