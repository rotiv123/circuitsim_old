//
// Created by vitor on 05-07-2015.
//

#ifndef CIRCUITSIM_ISIMULATION_H
#define CIRCUITSIM_ISIMULATION_H


#include <vector>
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

        std::vector<double> dc_solve()
        {
            return callr([=]()
                 {
                     std::vector<double> vec;
                     this->pimpl_.get().dc_solve([](void* st, double* data, int n)
                                                 {
                                                     auto vec = (std::vector<double> *)st;
                                                     for(int i = 0; i < n; ++i)
                                                     {
                                                         vec->push_back(data[i]);
                                                     }
                                                 }, &vec);

                     return vec;
                 });
        }

    private:
        handle<ISimulation, SIMULATION_IID> pimpl_;
    };


}

#endif //CIRCUITSIM_ISIMULATION_H
