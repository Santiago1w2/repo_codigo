
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<string> lab;
bool visitado[6][6] = {};
int caminos = 0;

int df[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void backtracking(int f, int c) {
    // Caso base: llegamos al destino
    if (f == n - 1 && c == m - 1) {
        caminos++;
        return;
    }

    // Marcamos la casilla actual
    visitado[f][c] = true;

    // Probamos los 4 movimientos
    for (int i = 0; i < 4; i++) {
        int nf = f + df[i];
        int nc = c + dc[i];

        // Verificamos que esté dentro del laberinto
        if (nf < 0 || nf >= n || nc < 0 || nc >= m) {
            continue;
        }

        // No entramos a paredes ni a casillas visitadas
        if (lab[nf][nc] == '#' || visitado[nf][nc]) {
            continue;
        }

        backtracking(nf, nc);
    }

    // Deshacemos la elección para probar otros caminos
    visitado[f][c] = false;
}

int main() {
    cin >> n >> m;

    lab.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> lab[i];
    }

    backtracking(0, 0);

    cout << caminos << '\n';

    return 0;
}
