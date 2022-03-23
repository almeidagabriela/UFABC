#include <stdio.h>

void converteTemperatura(double, double*, double*, double*, double*, double*, double*);

int main(){
    double celsius, kelvin, fahren, rankine, reaumur, romer, deslile;

    scanf("%lf", &celsius);

    converteTemperatura(celsius, &kelvin, &fahren, &rankine, &reaumur, &romer, &deslile);

    printf("%.1lf\n", kelvin);
    printf("%.1lf\n", fahren);
    printf("%.1lf\n", rankine);
    printf("%.1lf\n", reaumur);
    printf("%.1lf\n", romer);
    printf("%.1lf\n", deslile);

    return 0;
}

void converteTemperatura(double celsius, double *kelvin, double *fahren, double *rankine, double *reaumur, double *romer, double *deslile){
    *kelvin = celsius + 273.15;
    *fahren = (celsius * 9/5) + 32;
    *rankine = (*kelvin * 9/5);
    *reaumur = (celsius * 4/5);
    *romer = (celsius * 21/40) + 7.5;
    *deslile = (100 - celsius) * 3/2;
}