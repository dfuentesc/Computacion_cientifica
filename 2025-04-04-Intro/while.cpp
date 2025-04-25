// imprima los numeros del 1 al 10 usando while
#include <iostream> 

int main(void) 
{
    int n;

    n = 1;
    while (n <= 10) {
        std::cout << n << std::endl;
        ++n;  
    } 

    return 0;
}