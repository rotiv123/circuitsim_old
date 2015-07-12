//
// Created by vitor on 27-06-2015.
//

#include <string>
#include <exception>

#include "config.h"
#include "circuitsim.h"
#include "simulation.h"

static std::string& last_error() noexcept
{
    thread_local std::string e{""};
    return e;
}

const char* circuitsim_version()
{
    return circuitsim_VERSION;
}

void* circuitsim_new(int id)
{
    try
    {
        last_error() = "";
        switch(id)
        {
        case SIMULATION_IID:
            return static_cast<void*>(new simulation{});
        default:
            return nullptr;
        }
    }
    catch (const std::exception& e)
    {
        last_error() = e.what();
        return nullptr;
    }
}

void circuitsim_delete(int id, void* sim)
{
    try
    {
        last_error() = "";
        switch(id)
        {
        case SIMULATION_IID:
            delete static_cast<simulation*>(sim);
        default:
            return;
        }
    }
    catch (const std::exception& e)
    {
        last_error() = e.what();
    }
}

const char* circuitsim_last_error()
{
    return last_error().c_str();
}


simulation_t* circuitsim_simulation_new()
{
    return reinterpret_cast<simulation_t*>(circuitsim_new(SIMULATION_IID));
}


void circuitsim_simulation_load(simulation_t* self, const char *circuit)
{
    try
    {
        reinterpret_cast<simulation*>(self)->load(circuit);
    }
    catch (const std::exception& e)
    {
        last_error() = e.what();
    }
}


void circuitsim_simulation_delete(simulation_t* self)
{
    circuitsim_delete(SIMULATION_IID, reinterpret_cast<void*>(self));
}
