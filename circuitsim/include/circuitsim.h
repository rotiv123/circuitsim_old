//
// Created by vitor on 27-06-2015.
//

#ifndef CIRCUITSIM_CIRCUITSIM_H
#define CIRCUITSIM_CIRCUITSIM_H

#ifdef _DLL
#define CIRCUITSIM __declspec(dllexport)
#else
#define CIRCUITSIM
#endif

#define SIMULATION_IID 1

#ifdef __cplusplus
extern "C" {
#endif

	CIRCUITSIM const char* circuitsim_last_error();

	CIRCUITSIM const char* circuitsim_version();

	CIRCUITSIM void* circuitsim_new(int);

	CIRCUITSIM void circuitsim_delete(int, void*);

	/******************************************************************************/
	/*   simulation                                                               */
	/******************************************************************************/

	typedef void(*circuitsim_simulation_cb)(double* data, int n);

	struct simulation_t;

	CIRCUITSIM simulation_t* circuitsim_simulation_new();

	CIRCUITSIM void circuitsim_simulation_load(simulation_t* self, const char* circuit);

	CIRCUITSIM void circuitsim_simulation_dc_solve(simulation_t* self, circuitsim_simulation_cb cb);

	CIRCUITSIM void circuitsim_simulation_delete(simulation_t*);

#ifdef __cplusplus
}
#endif

#endif //CIRCUITSIM_CIRCUITSIM_H
