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

    unsigned max_node() const;

    void stamp(matrix& mat, unsigned n) const;

    template<typename Visitor>
    void visit(Visitor& v) const
    {
        switch (this->type_)
        {
            case R:
                v(this->r_);
                break;
            case V:
                v(this->v_);
                break;
            case I:
                v(this->i_);
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
#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4624)
#endif
    union
    {
        int nil_;
        resistor r_;
        voltage_source v_;
        current_source i_;
    };
#ifdef _MSC_VER
#pragma warning( pop )
#endif
    void reset();
};

#endif //CIRCUITSIM_COMPONENT_H
