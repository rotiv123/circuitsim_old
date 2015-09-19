//
// Created by vitor on 05-07-2015.
//

#include <cctype>

#include "parser.h"

parser::parser(const std::string& circuit)
        : pos_{circuit.cbegin()}, end_{circuit.cend()}
{
}

parser::~parser()
{
}

token parser::advance()
{
    for (; this->pos_ < this->end_ && std::isspace(*this->pos_); ++this->pos_)
    { }

    if (this->pos_ == this->end_)
    {
        return {this->end_, this->end_};
    }

    auto begin = this->pos_;
    for (; this->pos_ < this->end_ && !std::isspace(*this->pos_); ++this->pos_)
    { }

    return {begin, this->pos_};
}
