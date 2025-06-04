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
    const long int nsamples = std::atoi(argv[1]);
    const double tes1 = std::atof(argv[2]);
    double tes = tes1;
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> dis(0, 1);
    const long int NX = nsamples;
    double x[NX][NX]; // Matriz de los valores aleatorios
    int cont;

    int** matriz_dinamica = new int*[NX]; // Arreglo 2D dinámico
    
    for (int i = 0; i < NX; ++i) {
        matriz_dinamica[i] = new int[NX];
        for (int j = 0; j < NX; ++j) {
            matriz_dinamica[i][j] = 0; // Inicializa con 0s (modifica según necesites)
        }
    }

    for(int n = 0; n < nsamples; ++n) {
        for (int m = 0; m < nsamples; ++m){
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
    percola(matriz_vector, cont);

    for(int n = 0; n < nsamples; ++n) {
        for (int m = 0; m < nsamples; ++m){
            std::cout<< matriz_vector[n][m]<< "  " ;
        }
        std::cout << "\n" ;
    }
    std::cout << "\n";
    return 0;
}
