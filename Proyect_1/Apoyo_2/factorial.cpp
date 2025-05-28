#include "factorial.h"

long factorial(long number)
{
    if (0 == number) return 1;
    if (number < 0) {
        std::cerr << "Negative numbers not allowed. Returning -1\n";
        return -1;
    }
    return number < 0 ? number : factorial(number-1)*number;
    // number es menor o igual a 1 
    // ? si se cumple retorna el numero
    // : si no se cumple retorna factorial(number-1)*number
}