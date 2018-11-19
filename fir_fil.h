#ifndef FIR_FIL_H
#define FIR_FIL_H

double* fir_filter (double input[], double output[]) {
    double h[]={ 3.42591553E-0003, 1.98488129E-0002,-5.43602554E-0002, 2.56355684E-0002,
                 6.93667396E-0002,-6.39440064E-0002,-1.63419803E-0001, 4.29283935E-0001,
                4.29283935E-0001,-1.63419803E-0001,-6.39440064E-0002, 6.93667396E-0002,
                2.56355684E-0002,-5.43602554E-0002, 1.98488129E-0002,3.42591553E-0003};
    double acc=0;
    static double history[16] = { 0 };

    for(int i=0; i<1024; i++) {
        for (int k=15; k>=0; k--) {
            history[k]=history[k-1];
        }

        history[0]=input[i];
        acc=0;

        for (int j=0; j<16; j++) {
            acc+=history[j]*h[j];
        }
        output[i]=acc;
    }
    return output;
}


#endif // FIR_FIL_H
