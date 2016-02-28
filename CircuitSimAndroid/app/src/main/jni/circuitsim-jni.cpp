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
#include "circuitsim++.h"

extern "C"
{

jstring Java_com_rotiv_circuitsim_CircuitSimLib_version(JNIEnv *env, jobject)
{
    return env->NewStringUTF(circuitsim::version());
}

jlong Java_com_rotiv_circuitsim_CircuitSimLib_simLoad(JNIEnv *env, jobject, jstring c)
{
    const char *str = env->GetStringUTFChars(c, nullptr);
    auto sim = new circuitsim::simulation();
    sim->load(str);
    env->ReleaseStringUTFChars(c, str);
    return reinterpret_cast<jlong>(sim);
}

jdoubleArray Java_com_rotiv_circuitsim_CircuitSimLib_simDCSolve(JNIEnv *env, jobject, jlong p)
{
    auto sim = reinterpret_cast<circuitsim::simulation *>(p);
    auto vec = sim->dc_solve();

    auto output = env->NewDoubleArray((int)vec.size());
    env->SetDoubleArrayRegion(output, 0, (int)vec.size(), vec.data());

    return output;
}

void Java_com_rotiv_circuitsim_CircuitSimLib_simUnload(JNIEnv *env, jobject, jlong n)
{
    auto sim = reinterpret_cast<circuitsim::simulation *>(n);
    delete sim;
}

}