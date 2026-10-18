
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int w[12];
int peso[3] = {0, 0, 0};
int respuesta = INT_MAX;

void backtracking(int i) {
    if (i == n) {
        int maximo = max(peso[0], max(peso[1], peso[2]));
        respuesta = min(respuesta, maximo);
        return;
    }

    for (int persona = 0; persona < 3; persona++) {
        // Asignar la caja i a esta persona
        peso[persona] += w[i];

        backtracking(i + 1); //Avanzar

        // Deshacer la asignación
        peso[persona] -= w[i];
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    backtracking(0);

    cout << respuesta << '\n';

    return 0;
}
