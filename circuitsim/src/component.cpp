//
// Created by vitor on 12-07-2015.
//

#include "component.h"

component::component(resistor&& r)
    : type_{R}, r_{r}
{
}

component::component(const component& other)
    : type_{NIL}, nil_{0}
{
    *this = other;
}

component::component(component&& other)
    : type_{NIL}, nil_{0}
{
    *this = std::move(other);
}

component::~component()
{
    this->reset();
}

component& component::operator=(const component& other)
{
    this->reset();
    this->type_ = other.type_;
    switch (this->type_)
    {
    case R:
        this->r_ = other.r_;
        break;
    default:
        break;
    }

    return *this;
}

component& component::operator=(component&& other)
{
    this->reset();
    this->type_ = other.type_;
    switch (this->type_)
    {
    case R:
        this->r_ = std::move(other.r_);
        break;
    default:
        break;
    }

    return *this;
}

void component::reset()
{
    switch (this->type_)
    {
    case R:
        this->r_.~resistor();
        break;
    default:
        break;
    }
}
