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
 */
package com.rotiv.circuitsim;

import android.app.Activity;
import android.widget.TextView;
import android.os.Bundle;

public class Main extends Activity {
    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        /* Create a TextView and set its content.
         * the text is retrieved by calling a native
         * function.
         */
        TextView tv = new TextView(this);
        //tv.setText(CircuitSimLib.version());
        //setContentView(tv);

        CircuitSimLib.Simulation sim =new CircuitSimLib.Simulation("Vs1 1 0 DC 10 R1 1 2 100 R2 2 0 1000 R3 2 3 100 Vs2 3 0 DC 10 .end");
        double[] vec = sim.dcSolve();
        sim.unload();

        String out = "";

        for (int i = 0; i < vec.length; ++i)
        {
            out += vec[i] + "\n";
        }

        tv.setText(out);
        setContentView(tv);
    }
}
