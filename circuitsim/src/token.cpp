//
// Created by vitor on 05-07-2015.
//

#include "token.h"

std::string to_string(const token& t)
{
    return std::string{t.begin(), t.end()};
}