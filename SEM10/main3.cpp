
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N = 9;

vector<string> tablero(N);

vector<vector<bool>> fila(N, vector<bool>(N, false));
vector<vector<bool>> columna(N, vector<bool>(N, false));
vector<vector<bool>> bloque(N, vector<bool>(N, false));

int obtener_bloque(int i, int j) {
    return (i / 3) * 3 + j / 3;
}

bool back_tracking(int i, int j) {
    // Ya completamos todas las filas
    if (i == N) {
        return true;
    }

    // Calcular la siguiente casilla
    int sig_i = i;
    int sig_j = j + 1;

    if (sig_j == N) {
        sig_j = 0;
        sig_i++;
    }

    // Si ya tiene un numero, pasar a la siguiente
    if (tablero[i][j] != '.') {
        return back_tracking(sig_i, sig_j);
    }

    int b = obtener_bloque(i, j);

    // Probar los numeros del 1 al 9
    for (int num = 1; num <= 9; num++) {
        if (!fila[i][num - 1] &&
            !columna[j][num - 1] &&
            !bloque[b][num - 1]) {

            // Construir
            tablero[i][j] = '0' + num;

            fila[i][num - 1] = true;
            columna[j][num - 1] = true;
            bloque[b][num - 1] = true;

            if (back_tracking(sig_i, sig_j)) {
                return true;
            }

            // Retroceder
            tablero[i][j] = '.';

            fila[i][num - 1] = false;
            columna[j][num - 1] = false;
            bloque[b][num - 1] = false;
        }
    }

    return false;
}

int main() {
    // Leer las 9 filas
    for (int i = 0; i < N; i++) {
        cin >> tablero[i];
    }

    // Registrar los numeros que ya vienen en el tablero
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablero[i][j] != '.') {
                int num = tablero[i][j] - '0';
                int b = obtener_bloque(i, j);

                fila[i][num - 1] = true;
                columna[j][num - 1] = true;
                bloque[b][num - 1] = true;
            }
        }
    }

    back_tracking(0, 0);

    // Imprimir el tablero completo
    for (int i = 0; i < N; i++) {
        cout << tablero[i] << '\n';
    }

    return 0;
}
