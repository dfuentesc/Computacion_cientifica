#include <iostream>
#include "factorial.h"

int main(void)
{
    std::cout << factorial(-1) << std::endl;
    std::cout << factorial(-1.5) << std::endl;
    std::cout << factorial(0.5) << std::endl;
    std::cout << factorial(14) << std::endl;
    return 0;
}
