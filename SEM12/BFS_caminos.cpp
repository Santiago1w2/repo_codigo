
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

struct Arista {
    int u, v, w;
};

class Grafo {
public:
    int n, m;
    bool esDirigido;

    vector<vector<int>> matrizAdy;
    vector<vector<int>> listaAdy;
    vector<Arista> listaAristas;

    Grafo(int n, bool dirigido = false)
        : n(n), m(0), esDirigido(dirigido) {
        matrizAdy.assign(n + 1, vector<int>(n + 1, 0));
        listaAdy.resize(n + 1);
    }

    void agregarArista(int u, int v, int w = 1) {
        matrizAdy[u][v] = w;
        listaAdy[u].push_back(v);
        listaAristas.push_back({u, v, w});

        if (!esDirigido) {
            matrizAdy[v][u] = w;
            listaAdy[v].push_back(u);
        }

        m++;
    }

    bool sonAdyacentesMatriz(int u, int v) const {
        return matrizAdy[u][v] != 0;
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
    void BFS_caminos(int inicio, vector<int>&dist, vector<vector<int>>&padre){
        queue<int> cola;
        dist[inicio]=0;
        cola.push(inicio);
        while(!cola.empty()){
            int u = cola.front();
            cola.pop();
            for(int v: listaAdy[u]){
                if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    padre[v].push_back(u);
                    cola.push(v);
                } else if(dist[v]==dist[u]+1){
                    padre[v].push_back(u);
                }
            }
        }
    }
    void reconstruirCaminos(int actual, int inicio, vector<vector<int>>& padre, vector<int>&camino, vector<vector<int>>&caminos){
        camino.push_back(actual);
        if(actual==inicio){
            vector<int> aux=camino;
            reverse(aux.begin(),aux.end());
            caminos.push_back(aux);
        } else {
            for(int p: padre[actual]){
                reconstruirCaminos(p,inicio,padre,camino,caminos);
            }
        }
        camino.pop_back();
    }
};

int main() {
    int n,m;
    cin >> n >> m;
    Grafo g(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.agregarArista(u,v);
    }

    int origen, destino;
    cin >> origen >> destino;

    vector<int> distancia(n+1,-1);
    vector<vector<int>> padres(n+1);
    

    g.BFS_caminos(origen, distancia, padres);

    if (distancia[destino] == -1) {
        cout << "No existe camino\n";
        return 0;
    }

    vector<int> camino;
    vector<vector<int>> caminos;

    g.reconstruirCaminos(destino, origen, padres, camino, caminos);

    cout << "Distancia minima: " << distancia[destino] << "\n";
    cout << "Cantidad de caminos minimos: " << caminos.size() << "\n";

    for (auto c : caminos) {
        for (int v : c) cout << v << " ";
        cout << "\n";
    }

    return 0;
}

