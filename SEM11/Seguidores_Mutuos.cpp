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
    vector<bool> vistos;
    vector<int> contados;

    vector<vector<int>> listaAdy;

    Grafo(int n, bool dirigido = false) : n(n), m(0), esDirigido(dirigido) {
        listaAdy.resize(n + 1);
        vistos.resize(n+1,false);
        contados.resize(n+1,0);
    }

    void agregarArista(int u, int v, int w = 1) {
        contados[v]++;
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
    int contar() {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            vector<int> u = listaAdy[i];
            for (int v = 0; v < u.size(); v++) {
                int vecino = u[v];
                if (find(listaAdy[vecino].begin(),listaAdy[vecino].end(), i) != listaAdy[vecino].end()) {
                    cnt++;
                }
            }
        }
        return cnt / 2;
    }
    void max_contador(){
        int idx = 1;
        for(int i = 2; i <=n;i++){
            if(contados[i]>contados[idx]){
                idx = i;
            }
        }
        cout << " " << idx << " " << contados[idx];
    }
    void ver(){
        for(int i = 1; i <=n;i++){
            cout << "idx: " << i << "valor: " << contados[i] << "\n";
        }
    }
};

void obtenerVecinosGrilla(int f, int c, int R, int C, const vector<vector<bool>>& esPared) {
    int df[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    cout << "Vecinos de (" << f << ", " << c << "): ";
    for (int k = 0; k < 4; ++k) {
        int nf = f + df[k];
        int nc = c + dc[k];

        if (nf >= 0 && nf < R && nc >= 0 && nc < C && !esPared[nf][nc]) {
            cout << "(" << nf << ", " << nc << ") ";
        }
    }
    cout << "\n";
}

int main() {
    int n = 0, m = 0;
    cin >> n >>m;
    Grafo g(n, true);

    for(int i = 0; i < m ; i++){
        int u = 0, v = 0;
        cin>>u>>v;
        g.agregarArista(u,v);
    }
    cout<< g.contar();
    g.max_contador();
    return 0;
}