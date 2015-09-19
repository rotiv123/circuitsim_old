//
// Created by vitor on 12-07-2015.
//

#ifndef CIRCUITSIM_COMPONENT_H
#define CIRCUITSIM_COMPONENT_H

#include "resistor.h"
#include "voltage_source.h"
#include "current_source.h"

class component final
{
public:
    component(resistor&& r) noexcept;

    component(voltage_source&& v) noexcept;

    component(current_source&& i) noexcept;

    component(const component& other);

    component(component&& other) noexcept;

    ~component();

    component& operator=(const component& other);

    component& operator=(component&& other) noexcept;

    template<typename Visitor>
    void visit(const Visitor& v)
    {
        switch (this->type_)
        {
            case R:
                v.handle(this->r_);
                break;
            case V:
                v.handle(this->v_);
                break;
            case I:
                v.handle(this->i_);
                break;
            default:
                break;
        }
    }

private:
    enum
    {
        NIL, R, V, I
    } type_;
    union
    {
        int nil_;
        resistor r_;
        voltage_source v_;
        current_source i_;
    };

    void reset();
};

#endif //CIRCUITSIM_COMPONENT_H
