#include <random>
#include <iostream>
#include <cstdlib>
#include <clocale> 
#include <chrono> 
#include <vector>
#include <queue>
using namespace std;

struct val3d {
    int a, b, c, d;
};

bool percola(const vector<vector<int>>& matriz);


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
    double x[NX][NX]; // Matriz de los valores aleatorios
    bool grid[NX][NX];  // matriz llena de 0 o 1 

    int** matriz_dinamica = new int*[NX]; // Arreglo 2D dinámico
    for (int i = 0; i < NX; ++i) {
        matriz_dinamica[i] = new int[NX];
        for (int j = 0; j < NX; ++j) {
            matriz_dinamica[i][j] = 0; // Inicializa con 0s (modifica según necesites)
        }
    }

    // Convertir a vector<vector<int>> para usar en la función




    for(int n = 0; n < nsamples; ++n) {
        for (int m = 0; m < nsamples; ++m){
            x[n][m]= dis(gen);
        }
    }


    for(int n = 0; n < nsamples; ++n) {
        std::cout << "\n" ;
        for (int m = 0; m < nsamples; ++m){
            if (x[n][m] >= tes){
                matriz_dinamica[n][m] = 0;
                std::cout << "\033[48;5;208m  \033[0m"; 
            }
            else{
                matriz_dinamica[n][m] = 1;
                std::cout << "\033[44m  \033[0m";
                
            }
        }
    }

    std::cout << "\n";

    for(int n = 0; n < nsamples; ++n) {
        std::cout << "\n" ;
        for (int m = 0; m < nsamples; ++m){
            std::cout<< matriz_dinamica[n][m]<< "  " ;
        }
    }
    std::cout << "\n";

    vector<vector<int>> matriz_vector(NX, vector<int>(NX));
    for (int i = 0; i < NX; ++i) {
        for (int j = 0; j < NX; ++j) {
            matriz_vector[i][j] = matriz_dinamica[i][j];
        }
    }
    cout << (percola(matriz_vector) ? "Percola" : "No percola");

    return 0;
}

bool percola(const vector<vector<int>>& matriz) {
    int filas = matriz.size();
    if (filas == 0) return false;
    int columnas = matriz[0].size();
    if (columnas == 0) return false;

    vector<vector<bool>> visitado(filas, vector<bool>(columnas, false));
    queue<pair<int, int>> cola;

    // Inicializar con la fila superior
    for (int j = 0; j < columnas; ++j) {
        if (matriz[0][j] == 1 && !visitado[0][j]) {
            cola.push({0, j});
            visitado[0][j] = true;
        }
    }

    // Direcciones posibles: abajo, izquierda, derecha
    vector<pair<int, int>> direcciones = {{1, 0}, {0, -1}, {0, 1}};

    while (!cola.empty()) {
        auto [i, j] = cola.front();
        cola.pop();

        // Si llegamos a la última fila, hay percolación
        if (i == filas - 1) return true;

        // Explorar vecinos
        for (auto [di, dj] : direcciones) {
            int ni = i + di;
            int nj = j + dj;

            // Verificar límites y si no está visitado
            if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) {
                if (matriz[ni][nj] == 1 && !visitado[ni][nj]) {
                    visitado[ni][nj] = true;
                    cola.push({ni, nj});
                }
            }
        }
    }

    return false;
}
