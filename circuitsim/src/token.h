//
// Created by vitor on 05-07-2015.
//

#ifndef CIRCUITSIM_TOKEN_H
#define CIRCUITSIM_TOKEN_H

#include <cassert>
#include <string>

class token
{
public:
    token(std::string::const_iterator begin, std::string::const_iterator end)
            : begin_{begin}, end_{end}
    {
    }

    bool empty() const
    {
        return this->begin_ == this->end_;
    }

	std::string::const_iterator begin() const
    {
        return this->begin_;
    }

	std::string::const_iterator end() const
    {
        return this->end_;
    }

    explicit operator bool() const
    {
        return !this->empty();
    }

private:
	std::string::const_iterator begin_;
	std::string::const_iterator end_;
};

std::string to_string(const token& t);

#endif //CIRCUITSIM_TOKEN_H
