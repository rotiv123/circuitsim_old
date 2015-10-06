//
// Created by vitor on 05-07-2015.
//

#include <cctype>
#include <string>

#include "parser.h"

parser::parser(const char* circuit)
        : str_{circuit}, pos_{str_.cbegin()}
{
}

parser::~parser()
{
}

token parser::advance()
{
    for (; this->pos_ != this->str_.cend() && std::isspace(*this->pos_); ++this->pos_)
    {
    }

    if (this->pos_ == this->str_.cend())
    {
        return {this->str_.cend(), this->str_.cend()};
    }

    auto begin = this->pos_;
    for (; this->pos_ != this->str_.cend() && !std::isspace(*this->pos_); ++this->pos_)
    {
    }

    return {begin, this->pos_};
}
