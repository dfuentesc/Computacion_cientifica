// Mi primer programa
#include <iostream> 
#include <string> 

int main(void) 
{
    std::string name;
    std::cout << "Please write your name:" << std::endl;
    // solo me toma una linea cin
    //std::cin >> name;
    // me toma toda la linea
    std::getline (std::cin,name);
    std::cout << "hola" + name + "\n"; 
    return 0;
}