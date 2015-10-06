//
// Created by vitor on 05-07-2015.
//

#ifndef CIRCUITSIM_PARSER_H
#define CIRCUITSIM_PARSER_H

#include <string>

#include "token.h"

class parser final
{
public:
    parser(const char* circuit);

    ~parser();

    token advance();

private:
    const std::string str_;
    std::string::const_iterator pos_;
};


#endif //CIRCUITSIM_PARSER_H
