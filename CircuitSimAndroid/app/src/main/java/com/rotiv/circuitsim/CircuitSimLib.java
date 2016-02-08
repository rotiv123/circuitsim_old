package com.rotiv.circuitsim;

/**
 * Created by vitor on 07-02-2016.
 */
public class CircuitSimLib {

    public static native String version();

    public class Simulation {
        private long nativePtr = 0;

        public Simulation(String circuit) {
            this.nativePtr = simLoad(circuit);
        }

        public double[] dcSolve() {
            return simDCSolve(this.nativePtr);
        }

        public void unload() {
            simUnload(this.nativePtr);
            this.nativePtr = 0;
        }
    }

    private static native long simLoad(String circuit);

    private static native double[] simDCSolve(long nativePtr);

    private static native void simUnload(long nativePtr);

    static {
        System.loadLibrary("circuitsim");
    }
}
