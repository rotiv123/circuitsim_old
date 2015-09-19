//
// Created by vitor on 27-06-2015.
//

#ifndef CIRCUITSIM_SIMULATION_H
#define CIRCUITSIM_SIMULATION_H

#include <memory>
#include <vector>

#include "circuitsim/simulation.h"
#include "component.h"

class simulation final : public circuitsim::ISimulation
{
public:
    simulation();

    ~simulation();

    void load(const char* circuit) noexcept override;

    void step() noexcept override;

private:
    std::vector<component> components_;
};


#endif //CIRCUITSIM_SIMULATION_H
