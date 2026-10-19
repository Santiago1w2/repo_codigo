#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n;
vector<long long> entradas;
vector<int> resultados;
unordered_set<long long> registrados;

void backtracking(int i, int bloques) {
    if (i == n) {
        return;
    }

    long long x = entradas[i];

    if (registrados.find(x) == registrados.end()) {
        bool izquierda = registrados.find(x - 1) != registrados.end();
        bool derecha = registrados.find(x + 1) != registrados.end();

        if (!izquierda && !derecha) {
            bloques++;
        } else if (izquierda && derecha) {
            bloques--;
        }

        registrados.insert(x);
    }

    resultados.push_back(bloques);

    backtracking(i + 1, bloques);
}

int main() {
    cin >> n;

    entradas.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> entradas[i];
    }

    backtracking(0, 0);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << resultados[i];
    }

    cout << "\n";

    return 0;
}