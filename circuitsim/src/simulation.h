//
// Created by vitor on 27-06-2015.
//

#ifndef CIRCUITSIM_SIMULATION_H
#define CIRCUITSIM_SIMULATION_H

#include <memory>
#include <vector>

#include "circuitsim/simulation.h"
#include "component.h"

class simulation : public circuitsim::ISimulation
{
public:
    simulation();
    virtual ~simulation();

    virtual void load(const char* circuit) override;

    void step();

private:
    std::vector<component> components_;
};


#endif //CIRCUITSIM_SIMULATION_H
