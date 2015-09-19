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
    parser(const std::string& circuit);

    ~parser();

    token advance();

private:
    std::string::const_iterator pos_;
    std::string::const_iterator end_;
};


#endif //CIRCUITSIM_PARSER_H
