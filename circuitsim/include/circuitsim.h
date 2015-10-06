//
// Created by vitor on 27-06-2015.
//

#ifndef CIRCUITSIM_CIRCUITSIM_H
#define CIRCUITSIM_CIRCUITSIM_H

#define SIMULATION_IID 1

#ifdef __cplusplus
extern "C" {
#endif

const char* circuitsim_last_error();

const char* circuitsim_version();

void* circuitsim_new(int);

void circuitsim_delete(int, void*);

/******************************************************************************/
/*   simulation                                                               */
/******************************************************************************/

typedef void (*circuitsim_simulation_cb)(double* data, int n);

struct simulation_t;

simulation_t* circuitsim_simulation_new();

void circuitsim_simulation_load(simulation_t* self, const char* circuit);

void circuitsim_simulation_dc_solve(simulation_t* self, circuitsim_simulation_cb cb);

void circuitsim_simulation_delete(simulation_t*);

#ifdef __cplusplus
}
#endif

#endif //CIRCUITSIM_CIRCUITSIM_H
