//
// Created by vitor on 27-06-2015.
//


#include "simulation.h"
#include "parser.h"


simulation::simulation()
    : components_{}
{
}

simulation::~simulation()
{

}

void simulation::load(const char* circuit)
{
    parser p{circuit};
    auto t = p.advance();
    while (t)
    {
        auto c = *t.begin();
        switch (c)
        {
        case 'R':
            this->components_.emplace_back(resistor{t, p});
            break;
        case 'V':
            this->components_.emplace_back(voltage_source{t, p});
            break;
        }
        t = p.advance();
    }
}

void simulation::step()
{

}
