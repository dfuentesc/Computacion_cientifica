#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch_test_macros.hpp"

#include "percolation.h"

TEST_CASE("Percolación con p = 0 debe fallar para cualquier L") {
    for (int L : {4, 8, 16}) {
        std::vector<std::vector<int>> m(L, std::vector<int>(L, 0));
        int contador = 0;
        REQUIRE_FALSE(percola(m, contador));
        REQUIRE(contador == 0);
    }
}

TEST_CASE("Percolación con p = 1 debe tener éxito para cualquier L") {
    for (int L : {4, 8, 16}) {
        std::vector<std::vector<int>> m(L, std::vector<int>(L, 1));
        int contador = 0;
        REQUIRE(percola(m, contador));
        REQUIRE(contador == L * L);
    }
}

TEST_CASE("Caso manual 4x4 sin conexión de borde a borde (no percola)") {
    std::vector<std::vector<int>> m = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    int contador = 0;
    REQUIRE_FALSE(percola(m, contador));
    REQUIRE(contador == 0);
}

TEST_CASE("Caso manual 4x4 con camino vertical (sí percola)") {
    std::vector<std::vector<int>> m = {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0}
    };
    int contador = 0;
    REQUIRE(percola(m, contador));
    REQUIRE(contador == 4);
}
