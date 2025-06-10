#include <random>
#include <iostream>
#include <cstdlib>
#include <clocale> 
#include <chrono> 
#include <vector>
#include "percolation.h"

int main(int argc, char **argv) {
    const auto seed = std::chrono::high_resolution_clock::now()
                     .time_since_epoch().count();
    const long int nsamples = std::atol(argv[1]);
    const double tes = std::atof(argv[2]);
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> dis(0, 1);
    const long int NX = nsamples;
    double x[NX][NX]; // Matriz de los valores aleatorios
    int cont;

    int** matriz_dinamica = new int*[NX]; // Arreglo 2D dinámico
    
    for (int i = 0; i < NX; ++i) {
        matriz_dinamica[i] = new int[NX];
        for (int j = 0; j < NX; ++j) {
            matriz_dinamica[i][j] = 0; // Inicializa con 0s s
        }
    }

    for(int n = 0; n < NX; ++n) {
        for (int m = 0; m < NX; ++m){
            x[n][m]= dis(gen);
            if (x[n][m] >= tes){
                matriz_dinamica[n][m] = 0;
            }
            else{
                matriz_dinamica[n][m] = 1;

            }
        }
    }

    std::vector<std::vector<int>> matriz_vector(NX, std::vector<int>(NX));
    for (int i = 0; i < NX; ++i) {
        for (int j = 0; j < NX; ++j) {
            matriz_vector[i][j] = matriz_dinamica[i][j];
        }
    }
    //percola(matriz_vector, cont);
    auto start = std::chrono::steady_clock::now();
    percola(matriz_vector, cont);
    auto end = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration<double, std::milli>(end - start);
    std::cout << ms.count() << " " << tes << " " << NX; 
    std::cout << "\n";
}
