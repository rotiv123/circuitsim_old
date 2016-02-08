/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <jni.h>
#include <vector>
#include "circuitsim.h"

extern "C"
{

jstring Java_com_rotiv_circuitsim_CircuitSimLib_version(JNIEnv *env)
{
    return env->NewStringUTF(circuitsim_version());
}

jlong Java_com_rotiv_circuitsim_CircuitSimLib_simLoad(JNIEnv *env, jstring c)
{
    const char *str = env->GetStringUTFChars(c, 0);

    auto sim = circuitsim_simulation_new();
    circuitsim_simulation_load(sim, str);

    env->ReleaseStringUTFChars(c, str);
    return reinterpret_cast<jlong>(sim);
}

jdoubleArray Java_com_rotiv_circuitsim_CircuitSimLib_simDCSolve(JNIEnv *env, jlong p)
{
    std::vector<double> vec;
    auto sim = reinterpret_cast<simulation_t *>(p);
    circuitsim_simulation_dc_solve(
            sim,
            [](void *st, double *data, int n)
            {
                auto t = (std::vector<double> *) st;
                for (auto i = 0; i < n; ++i)
                {
                    t->push_back(data[i]);
                }
            },
            (void *) &vec);

    auto output = env->NewDoubleArray((int)vec.size());
    env->SetDoubleArrayRegion(output, 0, (int)vec.size(), vec.data());

    return output;
}

void Java_com_rotiv_circuitsim_CircuitSimLib_simUnload(JNIEnv *env, jlong n)
{
    auto sim = reinterpret_cast<simulation_t *>(n);
    circuitsim_simulation_delete(sim);
}

}