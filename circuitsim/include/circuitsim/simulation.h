//
// Created by vitor on 05-07-2015.
//

#ifndef CIRCUITSIM_ISIMULATION_H
#define CIRCUITSIM_ISIMULATION_H


#include "utils.h"

namespace circuitsim
{

struct ISimulation
{
    virtual ~ISimulation(){}

    virtual void load(const char* circuit) =0;
};

class simulation : public ISimulation
{
public:
    simulation() : pimpl_{}
    { }

    virtual ~simulation()
    { }

    virtual void load(const char *circuit) override
    {
        call([=]()
        {
            this->pimpl_.get().load(circuit);
        });
    }
private:
    handle<ISimulation, SIMULATION_IID> pimpl_;
};


}

#endif //CIRCUITSIM_ISIMULATION_H
