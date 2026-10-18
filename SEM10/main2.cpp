#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grilla = {{0, 3, 2}, {5, 4, 1}, {6, 8, 0}};
int n = 3;
int max_ruta = -1;

void back_tracking(int i, int j, int ruta) { // verificar, construir y retroceder
    // verificar
    if (i >= n || j >= n) {
        return; // retroceder
    }
    // construir
    ruta = ruta + grilla[i][j];

    // verificar
    if (i == n-1 && j == n-1) {
        max_ruta = max(ruta, max_ruta);
        return; //retroceder
    }
    // construir
    back_tracking(i+1, j, ruta); // hacer un down
    back_tracking(i, j+1, ruta); // hacer un right
}

int main() {
    back_tracking(0, 0, 0);
    cout << "\nmax ruta:"<< max_ruta;
    return 0;
}