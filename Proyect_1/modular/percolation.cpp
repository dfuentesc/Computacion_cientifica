#include "percolation.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <functional>


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
