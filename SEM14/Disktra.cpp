
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct Arista {
    int u, v, w;
};

class Grafo {
public:
    int n, m;
    bool esDirigido;

    vector<vector<pair<int, int>>> matrizAdy;
    vector<vector<int>> listaAdy;
    vector<Arista> listaAristas;

    Grafo(int n, bool dirigido = false)
        : n(n), m(0), esDirigido(dirigido) {
        matrizAdy.resize(n + 1);
        listaAdy.resize(n + 1);
    }

    void agregarArista(int u, int v, int w = 1) {
        matrizAdy[u].push_back({v, w});
        listaAdy[u].push_back(v);
        listaAristas.push_back({u, v, w});

        if (!esDirigido) {
            matrizAdy[v].push_back({u, w});
            listaAdy[v].push_back(u);
        }

        m++;
    }

    bool sonAdyacentesMatriz(int u, int v) const {
        for (size_t i = 0; i < matrizAdy[u].size(); ++i) {
            if (matrizAdy[u][i].first == v) return true;
        }
        return false;
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

    pair<vector<int>, vector<int>>
    construirListaCompacta() const {
        vector<int> grado(n + 2, 0);
        vector<int> inicio(n + 2, 0);

        for (const auto& a : listaAristas) {
            grado[a.u]++;

            if (!esDirigido) {
                grado[a.v]++;
            }
        }

        inicio[1] = 0;

        for (int u = 1; u <= n; ++u) {
            inicio[u + 1] = inicio[u] + grado[u];
        }

        vector<int> pos = inicio;
        vector<int> vecinos(inicio[n + 1]);

        for (const auto& a : listaAristas) {
            vecinos[pos[a.u]++] = a.v;

            if (!esDirigido) {
                vecinos[pos[a.v]++] = a.u;
            }
        }

        return {inicio, vecinos};
    }

    void djkstra(int s, vector<int>& dist, vector<int>& padre) {
        dist.assign(n + 1, INT_MAX);
        padre.assign(n + 1, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cola;

        dist[s] = 0;
        cola.push({0, s});

        while (!cola.empty()) {
            pair<int, int> actual = cola.top();
            cola.pop();

            int d = actual.first;
            int u = actual.second;

            if (d > dist[u]) continue;

            for (size_t i = 0; i < matrizAdy[u].size(); ++i) {
                int v = matrizAdy[u][i].first;
                int w = matrizAdy[u][i].second;

                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    padre[v] = u;
                    cola.push({dist[v], v});
                }
            }
        }
    }

    vector<int> reconstruirCamino(int s, int t, const vector<int>& padre) const {
        vector<int> camino;

        if (s == t) {
            camino.push_back(s);
            return camino;
        }

        if (t < 1 || t > n || padre[t] == -1) {
            return camino;
        }

        for (int v = t; v != -1; v = padre[v]) {
            camino.push_back(v);
        }

        reverse(camino.begin(), camino.end());

        if (camino.empty() || camino.front() != s) {
            return {};
        }

        return camino;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Grafo g(n, true);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.agregarArista(u, v, w);
    }

    int s, t;
    cin >> s >> t;

    vector<int> dist, padre;
    g.djkstra(s, dist, padre);

    if (dist[t] == INT_MAX) {
        cout << "No hay camino\n";
        return 0;
    }

    cout << dist[t] << "\n";

    vector<int> camino = g.reconstruirCamino(s, t, padre);
    for (size_t i = 0; i < camino.size(); ++i) {
        if (i) cout << " ";
        cout << camino[i];
    }
    cout << "\n";

    return 0;
}


