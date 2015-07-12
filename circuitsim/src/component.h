//
// Created by vitor on 12-07-2015.
//

#ifndef CIRCUITSIM_COMPONENT_H
#define CIRCUITSIM_COMPONENT_H

#include "resistor.h"

class component final
{
public:
    component(resistor&& r);

    component(const component& other);

    component(component&& other);

    ~component();

    component& operator=(const component& other);

    component& operator=(component&& other);

    template<typename V>
    void visit(const V& v)
    {
        switch(this->type_)
        {
        case R:
            v.handle(this->r_);
        default:
            break;
        }
    }

private:
    enum {NIL, R} type_;
    union
    {
        int nil_;
        resistor r_;
    };

    void reset();
};

#endif //CIRCUITSIM_COMPONENT_H
