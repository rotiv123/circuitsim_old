//
// Created by vitor on 27-06-2015.
//

#include <string>

//#include "config.h"
#include "utils.h"
#include "circuitsim.h"
#include "simulation.h"

std::string& last_error() noexcept
{
    thread_local std::string e{""};
    return e;
}

const char* circuitsim_version()
{
	return "1.0.0";// circuitsim_VERSION;
}

void* circuitsim_new(int id)
{
    void* result = nullptr;
    no_throw([&]()
             {
                 switch (id)
                 {
                     case SIMULATION_IID:
                         result = static_cast<void*>(new simulation{});
                         break;
                     default:
                         result = nullptr;
                         break;
                 }
             });

    return result;
}

void circuitsim_delete(int id, void* sim)
{
    no_throw([=]()
             {
                 switch (id)
                 {
                     case SIMULATION_IID:
                         delete static_cast<simulation*>(sim);
                         break;
                     default:
                         break;
                 }
             });
}

const char* circuitsim_last_error()
{
    return last_error().c_str();
}


simulation_t* circuitsim_simulation_new()
{
    return static_cast<simulation_t*>(circuitsim_new(SIMULATION_IID));
}

void circuitsim_simulation_load(simulation_t* self, const char* circuit)
{
    reinterpret_cast<simulation*>(self)->load(circuit);
}

void circuitsim_simulation_dc_solve(simulation_t* self, circuitsim_simulation_cb cb)
{
    reinterpret_cast<simulation*>(self)->dc_solve(cb);
}

void circuitsim_simulation_delete(simulation_t* self)
{
    circuitsim_delete(SIMULATION_IID, static_cast<void*>(self));
}
