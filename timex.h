#ifndef TIMEX_H
#define TIMEX_H
#include <qmath.h>

using namespace std;
int	Freq[] = {3000,5000,6000,8000,9000,10000,12000};
int Ampl[]={7,9,8,7,3,2,5};
int FreqMax= 12000;
double FreqD=2*FreqMax;
double timeD=(1/FreqD);

double* timeX(double X[], double timex[]){
    timex[0]=0;
    double z=timeD; int i=1;
    while (z<timeD*1024) {
        timex[i]=timeD*i;
        z+=timeD;
        i+=1;
    }
    for (int i=0; i<1024; i++) {
        X[i]=Ampl[0]*sin(2*M_PI*Freq[0]*timex[i])+
            Ampl[1]*sin(2*M_PI*Freq[1]*timex[i])+
            Ampl[2]*sin(2*M_PI*Freq[2]*timex[i])+
            Ampl[3]*sin(2*M_PI*Freq[3]*timex[i])+
            Ampl[4]*sin(2*M_PI*Freq[4]*timex[i])+
            Ampl[5]*sin(2*M_PI*Freq[5]*timex[i])+
            Ampl[6]*sin(2*M_PI*Freq[6]*timex[i]);
    }
    return X, timex;
}

#endif // TIMEX_H
