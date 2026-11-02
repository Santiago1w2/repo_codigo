
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Arista {
    int u, v, w;
};

class Grafo {
public:
    int n, m;
    bool esDirigido;

    vector<vector<int>> listaAdy;
    map<pair<int, int>, int> cantidad;

    Grafo(int n, bool dirigido = false):n(n), m(0), esDirigido(dirigido) {
        listaAdy.resize(n + 1);
    }

    void agregarArista(int u, int v, int w = 1) {
        listaAdy[u].push_back(v);
        if (!esDirigido && u != v) {
            listaAdy[v].push_back(u);
        }
        if (u > v) swap(u, v);
        cantidad[{u, v}]++;
        m++;
    }

    int contarCables(int u, int v) {
        if (u > v) swap(u, v);
        return cantidad[{u, v}];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    Grafo g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.agregarArista(u, v);
    }
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << g.contarCables(u, v) << '\n';
    }
    return 0;
}
