
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<vector<int>> sudoku;

bool validar(int f, int c, int num) {
    // Revisar la fila
    for (int j = 0; j < n; j++) {
        if (sudoku[f][j] == num) {
            return false;
        }
    }

    // Revisar la columna
    for (int i = 0; i < n; i++) {
        if (sudoku[i][c] == num) {
            return false;
        }
    }

    // Revisar el subcuadro
    int tam = sqrt(n);
    int inicioF = (f / tam) * tam;
    int inicioC = (c / tam) * tam;

    for (int i = inicioF; i < inicioF + tam; i++) {
        for (int j = inicioC; j < inicioC + tam; j++) {
            if (sudoku[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool backtracking(int pos) {
    // Caso base: completamos todas las casillas
    if (pos == n * n) {
        return true;
    }

    int f = pos / n;
    int c = pos % n;

    // Si ya tiene número, avanzamos
    if (sudoku[f][c] != 0) {
        return backtracking(pos + 1);
    }

    // Probamos todos los números posibles
    for (int num = 1; num <= n; num++) {
        if (validar(f, c, num)) {
            sudoku[f][c] = num;

            if (backtracking(pos + 1)) {
                return true;
            }

            // Deshacemos la elección
            sudoku[f][c] = 0;
        }
    }

    return false;
}

int main() {
    cin >> n;

    sudoku.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sudoku[i][j];
        }
    }

    if (backtracking(0)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << '\n';
        }
    } else {
        cout << "No hay solucion\n";
    }

    return 0;
}
