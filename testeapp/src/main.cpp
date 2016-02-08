#include <iostream>

#include "circuitsim++.h"

int main()
{
    circuitsim::simulation sim;

    sim.load("Vs1 1 0 DC 10 R1 1 2 100 R2 2 0 1000 R3 2 3 100 Vs2 3 0 DC 10 .end");

    sim.dc_solve([](void* state, double* data, int n)
                 {
                     for (auto i = 0; i < n; ++i)
                     {
                         std::cout << data[i] << std::endl;
                     }
                 }, nullptr);

    std::cout << "Olá, World! " << circuitsim::version() << std::endl;
}
