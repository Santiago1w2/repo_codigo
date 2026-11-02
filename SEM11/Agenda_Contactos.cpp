
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Arista {
    int u, v, w;
};

class Grafo {
public:
    int n, m;
    bool esDirigido;

    vector<vector<int>> listaAdy;

    Grafo(int n, bool dirigido = false)
        : n(n), m(0), esDirigido(dirigido) {
        listaAdy.resize(n + 1);
    }

    void agregarArista(int u, int v, int w = 1) {
        listaAdy[u].push_back(v);

        if (!esDirigido) {
            listaAdy[v].push_back(u);
        }

        m++;
    }


    bool sonAdyacentesLista(int u, int v) const {
        for (int vecino : listaAdy[u]) {
            if (vecino == v) return true;
        }
        return false;
    }

    void quitarAristaLista(int u, int v) {
        for (size_t i = 0; i < listaAdy[u].size(); ++i) {
            if (listaAdy[u][i] == v) {
                listaAdy[u][i] = listaAdy[u].back();
                listaAdy[u].pop_back();
                break;
            }
        }

        if (!esDirigido) {
            for (size_t j = 0; j < listaAdy[v].size(); ++j) {
                if (listaAdy[v][j] == u) {
                    listaAdy[v][j] = listaAdy[v].back();
                    listaAdy[v].pop_back();
                    break;
                }
            }
        }
    }

    vector<vector<int>> obtenerTranspuesto() const {
        vector<vector<int>> adjT(n + 1);

        for (int u = 1; u <= n; ++u) {
            for (int v : listaAdy[u]) {
                adjT[v].push_back(u);
            }
        }

        return adjT;
    }

    int vecinosComunes(int u, int v) const {
        vector<bool> marca(n + 1, false);
        int cnt = 0;
        for (int x : listaAdy[u]) {
            marca[x] = true;
        }
        for (int y : listaAdy[v]) {
            if (marca[y]) cnt++;
        }
        return cnt;
    }
    int k_nesimo(int u, int k) {
        if (listaAdy[u].size() < k) {
            return -1;
        }
        return listaAdy[u][k - 1];
    }
    int cantidad_menor(int u, int x) {
        return upper_bound(listaAdy[u].begin(),listaAdy[u].end(),x)-listaAdy[u].begin();
    }
    void ordenarListas() {
        for (int u = 1; u <= n; u++) {
            sort(listaAdy[u].begin(), listaAdy[u].end());
        }
    }
};

int main() {
    int n = 0, m = 0, q = 0;
    cin >> n >> m >>q;

    Grafo g(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.agregarArista(u, v);
    }
    g.ordenarListas();
    for(int j = 0; j < q;j++){
        int op = 0, u = 0, x = 0;
        cin >> op >> u >> x;
        if(op==1){
            cout << g.k_nesimo(u,x) << "\n";
        } else if (op==2){
            cout << g.cantidad_menor(u,x)<<"\n";
        }
    }

    return 0;
}
