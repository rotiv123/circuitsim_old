#include <iostream>

#include "circuitsim++.h"

int main()
{
    circuitsim::simulation sim;

    sim.load("Vs 1 0 DC 5 Rload 1 0 100");

    std::cout << "Olá, World! " << circuitsim::version() << std::endl;
}
