#include <iostream>
#include <vector>

using namespace std;

struct Arista {
    int u, v, w;
};

class Grafo {
public:
    int n, m;
    bool esDirigido;

    vector<vector<int>> listaAdy;
    vector<Arista> listaAristas;

    Grafo(int n, bool dirigido = false):n(n), m(0), esDirigido(dirigido) {
        listaAdy.resize(n + 1);
    }

    void agregarArista(int u, int v, int w = 1) {
        listaAdy[u].push_back(v);
        listaAristas.push_back({u, v, w});
        if (!esDirigido) {
            listaAdy[v].push_back(u);
        }
        m++;
    }
    int vecinosComunes(int u, int v) const {
        vector<bool> marca(n + 1, false);
        int cnt = 0;
        for (int x : listaAdy[u]) {
            marca[x] = true;
        }
        for (int y : listaAdy[v]) {
            if (marca[y]) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    Grafo g(n, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.agregarArista(u, v);
    }
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << g.vecinosComunes(u, v) << '\n';
    }
    return 0;
}
