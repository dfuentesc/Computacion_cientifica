#include <iostream>
#include <cmath>

typedef float REAL;

REAL sumk (int k);
REAL sumk2 (int k);

int main (void){

    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);
    REAL delta = 0.0;
    for (int k = 1; k <= 1000; k++){
        delta = fabs(1-sumk(k)/sumk2(k));
        std::cout << k << "\t" << sumk(k)  << "\t" << sumk2(k) << "\t" << delta << "\n";
    }
    //std::cout << sumk(1) << "\n";
    return 0;

}

//implementation
REAL sumk (int k)
{
    REAL suma = 0.0;
    for (int ii = 1; ii <= k; ii++){
        suma += 1.0/(ii);
    }
    return suma;

}

REAL sumk2 (int k)
{
    REAL suma = 0.0;
    for (int ii = k; ii >= 1 ; ii--){
        suma += 1.0/(ii);
    }


    return suma ;

}