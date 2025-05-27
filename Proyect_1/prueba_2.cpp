#include <random>
#include <iostream>
#include <cstdlib>
#include <clocale> 
#include <chrono> 
#include <vector>
#include <queue>
#include <functional> 
//using namespace std;


bool percola(std::vector<std::vector<int>>& matriz, int& contador);


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
    int cont;

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
                //std::cout << "\033[42m  \033[0m";  // Fondo verde
                
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
    std::cout << (percola(matriz_vector, cont) ? "Percola" : "No percola") << "\n";
    std::cout << cont << "\n";

     for(int n = 0; n < nsamples; ++n) {
        std::cout << "\n" ;
        for (int m = 0; m < nsamples; ++m){
           // std::cout<< matriz_vector[n][m]<< "  " ;
            switch (matriz_vector[n][m]) {
                case 1:
                    std::cout << "\033[44m  \033[0m";
                    break;
                case 2:
                    std::cout << "\033[42m  \033[0m";
                    break;
                case 0:
                    std::cout << "\033[48;5;208m  \033[0m";
                    break;
                default:
                    std::cout << "\033[48;5;208m  \033[0m";
            }
        }
    }
    std::cout << "\n";

    return 0;
}

bool percola(std::vector<std::vector<int>>& matriz, int& contador) {
    int filas = matriz.size();
    if (filas == 0) return false;
    int columnas = matriz[0].size();
    if (columnas == 0) return false;

    std::vector<std::pair<int, int>> direcciones = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool exito = false;
    contador = 0;

    // Función auxiliar para BFS que marca el clúster
    auto bfs = [&](int inicio_i, int inicio_j, std::function<bool(int, int)> esObjetivo) {
        std::vector<std::vector<bool>> visitado(filas, std::vector<bool>(columnas, false));
        std::queue<std::pair<int, int>> cola;
        bool encontroObjetivo = false;

        if (matriz[inicio_i][inicio_j] == 1) {
            cola.push({inicio_i, inicio_j});
            visitado[inicio_i][inicio_j] = true;
        }

        while (!cola.empty()) {
            auto [i, j] = cola.front();
            cola.pop();

            if (esObjetivo(i, j)) encontroObjetivo = true;

            for (auto [di, dj] : direcciones) {
                int ni = i + di;
                int nj = j + dj;

                if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) {
                    if (matriz[ni][nj] == 1 && !visitado[ni][nj]) {
                        visitado[ni][nj] = true;
                        cola.push({ni, nj});
                    }
                }
            }
        }

        // Marcar el clúster si se encontró el objetivo
        if (encontroObjetivo) {
            for (int i = 0; i < filas; ++i) {
                for (int j = 0; j < columnas; ++j) {
                    if (visitado[i][j]) {
                        matriz[i][j] = 2;  // Marcamos con 2
                        contador++;
                    }
                }
            }
            exito = true;
        }

        return encontroObjetivo;
    };

    // Percolación vertical (desde toda la fila superior)
    for (int j = 0; j < columnas; ++j) {
        if (bfs(0, j, [filas](int i, int j) { return i == filas - 1; })) {
            return true;
        }
    }

    // Percolación horizontal (desde toda la columna izquierda)
    for (int i = 0; i < filas; ++i) {
        if (bfs(i, 0, [columnas](int i, int j) { return j == columnas - 1; })) {
            return true;
        }
    }

    return exito;
}