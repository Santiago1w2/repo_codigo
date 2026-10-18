#include <cmath>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<vector<int>> grilla = {{0, 3, 2}, {5, 4, 1}, {6, 8, 0}};
int n = 3;
int total_pasos = 2 * (n-1);
int total_mask = pow(2, total_pasos);
int max_ruta = -1;

int main() {
    for (int mask = 0; mask < total_mask; mask++) {
        int i = 0, j = 0;
        int ruta = 0;
        for (int p = 0; p < total_pasos; p++) {
            if ((mask >> p) & 1){// 0 -> DOWN y 1 -> RIGHT
                j = j + 1;
            } else {
                i = i + 1;
            }
            if (i <= n-1 && j <= n-1) {
                ruta = ruta + grilla[i][j];
            }
        }
        cout << "ruta: "<<mask<<":" <<ruta<<"\n";
        max_ruta = max(max_ruta, ruta);
    }
    cout << "\nmax ruta:"<< max_ruta;
    return 0;
}