#include <iostream>
#include <vector>

int n; //numero de nodos
int m; //numero de aristas
/*
[-1][0] 0 arriba
[1][0] 1 abajo
[0][-1] 2 izq
[0][1] 3 der
formula de los 8 vecinos 
*/

struct Grafo {
    int n;
    std::vector<std::vector<int>> matriz_adyacencia;

    Grafo(int n) : n(n), matriz_adyacencia(n, std::vector<int>(n, 0)) {
    }
};


int main(){
    int n = 5;

    return 0;
}