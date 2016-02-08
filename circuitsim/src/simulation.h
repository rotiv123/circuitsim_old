//
// Created by vitor on 27-06-2015.
//

#ifndef CIRCUITSIM_SIMULATION_H
#define CIRCUITSIM_SIMULATION_H

#include <memory>
#include <vector>
#include <string>

#include "matrix.h"
#include "circuitsim/simulation.h"
#include "component.h"

class simulation final : public circuitsim::ISimulation
{
public:
    simulation();

    ~simulation();

    void load(const char* circuit) noexcept override;

    void dc_solve(circuitsim_simulation_cb cb, void* state) noexcept override;

private:
    std::vector<double> solution_;
    std::vector<component> components_;
    std::unique_ptr<matrix> mat_;
    unsigned n_;
};


#endif //CIRCUITSIM_SIMULATION_H
