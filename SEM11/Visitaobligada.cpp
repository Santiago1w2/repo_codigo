
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
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
    vector<int> bfs(int inicio){
        vector<int> dist(n+1,-1);
        queue<int>cola;
        dist[inicio]=0;
        cola.push(inicio);
        while(!cola.empty()){
            int u = cola.front();
            cola.pop();
            for(int v: listaAdy[u]){
                if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    cola.push(v);
                }
                
            }
        }
        return dist;
    }
};

int main() {
    int n, m,x;
    cin >> n >> m>>x;
    Grafo g(n);
    for(int i = 1; i <=m; i++){
        int u,v;
        cin>>u>>v;
        g.agregarArista(u,v);

    }
    vector<int>dist1 = g.bfs(1);
    vector<int>distx = g.bfs(x);
    if(dist1[x]==-1 || distx[n]==-1){
        cout << -1;
    } else {
        cout << dist1[x]+distx[n];
    }
    return 0;
}
