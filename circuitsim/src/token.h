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
    typedef typename std::string::const_iterator const_iterator;

    token(const_iterator begin, const_iterator end)
            : begin_{begin}, end_{end}
    {
        assert(this->begin_ <= this->end_);
    }

//    token(std::string&& str)
//        : str_{std::move(str)}
//    {
//    }


    bool empty() const
    {
        return this->begin_ == this->end_;
//        return this->str_.empty();
    }

//    const std::string& str() const
//    {
//        return this->str_;
//    }

    const_iterator begin() const
    {
        return this->begin_;
    }

    const_iterator end() const
    {
        return this->end_;
    }

    explicit operator bool() const
    {
        return !this->empty();
    }

private:
    const_iterator begin_;
    const_iterator end_;
//    std::string str_;
};

std::string to_string(const token& t);

#endif //CIRCUITSIM_TOKEN_H
