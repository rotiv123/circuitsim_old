#include <iostream>
#include <vector>
#include "circuitsim++.h"

int main()
{
    circuitsim::simulation sim;

    sim.load("Vs1 1 0 DC 10 R1 1 2 100 R2 2 0 1000 R3 2 3 100 Vs2 3 0 DC 10 .end");

    auto vec = sim.dc_solve();

    for (auto x : vec)
    {
        std::cout << x << std::endl;
    }

    std::cout << "Olá, World! " << circuitsim::version() << std::endl;
}
