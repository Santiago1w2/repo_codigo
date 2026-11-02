
#include <iostream>
#include <vector>
#include <unordered_set>

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
    void dfs(int u,vector<bool>&visitados){
        visitados[u]=true;
        for(int v: listaAdy[u]){
            if(!visitados[v]){
                dfs(v,visitados);
            }
        }
    }
    void verificar(){
        if(m!=n-1){
            cout << "NO";
            return;
        }
        for(int i = 1; i <= n;i++){
            if(listaAdy[i].size()>2){
                cout << "NO";
                return;
            }
        }
        vector<bool> visitados(n+1,false);

        dfs(1,visitados);
        for(int i = 1; i <= n; i++){
            if(!visitados[i]){
                cout << "NO";
                return;
            }
        }
        cout << "SI";
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Grafo g(n, false);
    for(int i = 1; i <=m; i++){
        int v = 0, u = 0;
        cin>> u >> v;
        g.agregarArista(u,v);
    }
    g.verificar();
    return 0;
}
