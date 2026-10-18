
#include <iostream>
#include <string>
using namespace std;

int n;
string cadena;

void backtracking(int abiertos, int cerrados) {
    // Evaluar: ya completamos la cadena
    if (cadena.size() == 2 * n) {
        cout << cadena << '\n';
        return;
    }

    // Avanzar: agregar '('
    if (abiertos < n) {
        cadena.push_back('(');
        backtracking(abiertos + 1, cerrados);
        cadena.pop_back(); // Retroceder
    }

    // Avanzar: agregar ')'
    if (cerrados < abiertos) {
        cadena.push_back(')');
        backtracking(abiertos, cerrados + 1);
        cadena.pop_back(); // Retroceder
    }
}

int main() {
    cin >> n;
    backtracking(0, 0);
    return 0;
}
