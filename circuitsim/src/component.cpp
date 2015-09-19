//
// Created by vitor on 12-07-2015.
//

#include "component.h"

component::component(resistor&& r) noexcept
        : type_{R}, r_{r}
{
}

component::component(voltage_source&& v) noexcept
        : type_{V}, v_{v}
{
}

component::component(current_source&& i) noexcept
        : type_{I}, i_{i}
{
}

component::component(const component& other)
        : type_{NIL}, nil_{0}
{
    *this = other;
}

component::component(component&& other) noexcept
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
    if (this != &other)
    {
        this->reset();
        this->type_ = other.type_;
        switch (this->type_)
        {
            case R:
                new(&this->r_) resistor{other.r_};
                break;
            case V:
                new(&this->v_) voltage_source{other.v_};
                break;
            case I:
                new(&this->i_) current_source{other.i_};
                break;
            default:
                break;
        }
    }

    return *this;
}

component& component::operator=(component&& other) noexcept
{
    if (this != &other)
    {
        this->reset();
        this->type_ = other.type_;
        switch (this->type_)
        {
            case R:
                new(&this->r_) resistor{std::move(other.r_)};
                break;
            case V:
                new(&this->v_) voltage_source{std::move(other.v_)};
                break;
            case I:
                new(&this->i_) current_source{std::move(other.i_)};
                break;
            default:
                break;
        }
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
        case V:
            this->v_.~voltage_source();
            break;
        case I:
            this->i_.~current_source();
            break;
        default:
            break;
    }
}
