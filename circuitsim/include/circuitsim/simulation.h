//
// Created by vitor on 05-07-2015.
//

#ifndef CIRCUITSIM_ISIMULATION_H
#define CIRCUITSIM_ISIMULATION_H


#include "circuitsim.h"
#include "utils.h"

namespace circuitsim
{

    struct ISimulation
    {
        virtual ~ISimulation()
        { }

        virtual void load(const char* circuit) noexcept = 0;

        virtual void dc_solve(circuitsim_simulation_cb cb, void* state = nullptr) noexcept = 0;
    };

    class simulation final
    {
    public:
        simulation() : pimpl_{}
        { }

        ~simulation()
        { }

        void load(const char* circuit)
        {
            call([=]()
                 {
                     this->pimpl_.get().load(circuit);
                 });
        }

        void dc_solve(circuitsim_simulation_cb cb, void* state = nullptr)
        {
            call([=]()
                 {
                     this->pimpl_.get().dc_solve(cb, state);
                 });
        }

    private:
        handle<ISimulation, SIMULATION_IID> pimpl_;
    };


}

#endif //CIRCUITSIM_ISIMULATION_H
