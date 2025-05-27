#include <random>
#include <iostream>
#include <cstdlib>
#include <clocale> 
#include <chrono> 
#include <vector>
#include <queue>
//using namespace std;


bool percola(const std::vector<std::vector<int>>& matriz);


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

 /*   for(int n = 0; n < nsamples; ++n) {
        std::cout << "\n" ;
        for (int m = 0; m < nsamples; ++m){
            std::cout<< matriz_dinamica[n][m]<< "  " ;
        }
    }
    std::cout << "\n";
*/
    std::vector<std::vector<int>> matriz_vector(NX, std::vector<int>(NX));
    for (int i = 0; i < NX; ++i) {
        for (int j = 0; j < NX; ++j) {
            matriz_vector[i][j] = matriz_dinamica[i][j];
        }
    }
    std::cout << (percola(matriz_vector) ? "Percola" : "No percola") << "\n";

    return 0;
}



bool percola(const std::vector<std::vector<int>>& matriz) {
    int filas = matriz.size();
    if (filas == 0) return false;
    int columnas = matriz[0].size();
    if (columnas == 0) return false;

    // Direcciones permitidas: arriba, abajo, izquierda, derecha
    std::vector<std::pair<int, int>> direcciones = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // --------------------------------------------
    // Verificación vertical (arriba -> abajo)
    // --------------------------------------------
    std::vector<std::vector<bool>> visitado_vertical(filas, std::vector<bool>(columnas, false));
    std::queue<std::pair<int, int>> cola_vertical;

    // Inicializar con la fila superior
    for (int j = 0; j < columnas; ++j) {
        if (matriz[0][j] == 1 && !visitado_vertical[0][j]) {
            cola_vertical.push(std::make_pair(0, j));
            visitado_vertical[0][j] = true;
        }
    }

    // BFS para percolación vertical
    while (!cola_vertical.empty()) {
        auto [i, j] = cola_vertical.front();
        cola_vertical.pop();

        if (i == filas - 1) return true; // Éxito vertical

        for (auto [di, dj] : direcciones) {
            int ni = i + di;
            int nj = j + dj;

            if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) {
                if (matriz[ni][nj] == 1 && !visitado_vertical[ni][nj]) {
                    visitado_vertical[ni][nj] = true;
                    cola_vertical.push(std::make_pair(ni, nj));
                }
            }
        }
    }

    // --------------------------------------------
    // Verificación horizontal (izquierda -> derecha)
    // --------------------------------------------
    std::vector<std::vector<bool>> visitado_horizontal(filas, std::vector<bool>(columnas, false));
    std::queue<std::pair<int, int>> cola_horizontal;

    // Inicializar con la columna izquierda
    for (int i = 0; i < filas; ++i) {
        if (matriz[i][0] == 1 && !visitado_horizontal[i][0]) {
            cola_horizontal.push(std::make_pair(i, 0));
            visitado_horizontal[i][0] = true;
        }
    }

    // BFS para percolación horizontal
    while (!cola_horizontal.empty()) {
        auto [i, j] = cola_horizontal.front();
        cola_horizontal.pop();

        if (j == columnas - 1) return true; // Éxito horizontal

        for (auto [di, dj] : direcciones) {
            int ni = i + di;
            int nj = j + dj;

            if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) {
                if (matriz[ni][nj] == 1 && !visitado_horizontal[ni][nj]) {
                    visitado_horizontal[ni][nj] = true;
                    cola_horizontal.push(std::make_pair(ni, nj));
                }
            }
        }
    }

    return false; // No hay percolación en ninguna dirección
}