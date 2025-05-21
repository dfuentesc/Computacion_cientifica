#include <random>
#include <iostream>
#include <cstdlib>
#include <clocale> 
#include <chrono> 

int main(int argc, char **argv)
{
    const auto seed = std::chrono::high_resolution_clock::now()
                     .time_since_epoch().count();
    const int nsamples = std::atoi(argv[1]);
    const double tes1 = std::atol(argv[2]);
    double tes = tes1/100.0;
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> dis(0, 1);
    const int NX = nsamples;
    double x[NX][NX];

    bool grid[NX][NX];  // Matriz de percolación (1 = celda abierta/azul, 0 = cerrada/naranja)

    // Llenar la matriz (adaptado de tu código original)

    for(int n = 0; n < nsamples; ++n) {
        for (int m = 0; m < nsamples; ++m){
            x[n][m]= dis(gen);
        }
    }

 /*   for(int n = 0; n < nsamples; ++n) {
        std::cout << "\n" ;
        for (int m = 0; m < nsamples; ++m){
            std::cout << x[n][m] << " " ;
        }
    }
*/

    for(int n = 0; n < nsamples; ++n) {
        std::cout << "\n" ;
        for (int m = 0; m < nsamples; ++m){
            if (x[n][m] >= tes){
                std::cout << "\033[48;5;208m  \033[0m"; 
            }
            else{
                std::cout << "\033[44m  \033[0m"; 
            }
        }
    }

    std::cout << "\n";
    return 0;
}