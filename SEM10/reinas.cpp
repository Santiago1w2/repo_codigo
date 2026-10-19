#include <iostream>
#include <vector>

std::vector<bool> d1;
std::vector<bool>d2;
std::vector<bool>col;
std::vector<int>pos;
std::vector<std::string> tablero;
int n;
long long formas;
void reinas(int f){
    if(f==n){
        formas++;
        return;
    }
    for (int c = 0; c < n;c++){
        if( tablero[f][c] == '.' && !col[c] && !d1[f - c +n-1] && !d2[f+c]){
            col[c]=true;
            d1[f - c +n-1]=true;
            d2[f+c]=true;
            pos[f]=c;
            reinas(f + 1);
            col[c]=false;
            d1[f - c +n-1]=false;
            d2[f+c]=false;
        }
    }
}
long long contar(int f) {
    // Caso base: todas las filas tienen una reina
    if (f == n) {
        return 1;
    }

    long long total = 0;

    for (int c = 0; c < n; c++) {
        if (tablero[f][c] == '.' &&
            !col[c] &&
            !d1[f - c + n - 1] &&
            !d2[f + c]) {

            // Colocar reina
            col[c] = true;
            d1[f - c + n - 1] = true;
            d2[f + c] = true;

            // Contar las formas de completar las siguientes filas
            total += contar(f + 1);

            // Retirar reina para probar otra columna
            col[c] = false;
            d1[f - c + n - 1] = false;
            d2[f + c] = false;
        }
    }

    return total;
}

int main() {
    std::cin >> n;

    tablero.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> tablero[i];
    }

    d1.assign(2 * n - 1, false);
    d2.assign(2 * n - 1, false);
    col.assign(n, false);
    pos.resize(n);

    reinas(0);
    std::cout << contar(0) << "\n";

    std::cout << formas << '\n';

    return 0;
}