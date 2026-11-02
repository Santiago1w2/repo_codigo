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
    vector<int> df = {-1,1,0,0};
    vector<int> dc = {0,0,1,-1};
    vector<int> grados = {0,0,0,0,0};
    vector<vector<int>> matrizAdy;
    vector<vector<int>> listaAdy;
    vector<Arista> listaAristas;
    vector<string> mapa;

    Grafo(int n, bool dirigido = false) : n(n), m(0),mapa(n), esDirigido(dirigido) {
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

    pair<vector<int>, vector<int>> construirListaCompacta() const {
        vector<int> grado(n + 2, 0);
        vector<int> inicio(n + 2, 0);

        for (const auto& a : listaAristas) {
            grado[a.u]++;
            if (!esDirigido) grado[a.v]++;
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
    void cargar_mapa(){
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                if(mapa[i][j]=='.'){
                    continue;
                }
                int u = i * m + j;
                for(int k = 0; k < 4;k++){
                    int nf = i + df[k];
                    int nc = j + dc[k];
                    if(nf>=0 && nf < n && nc >=0 && nc < m && mapa[nf][nc]=='#'){
                        int v = nf * m + nc;
                        listaAdy[u].push_back(v);
                    }
                }

            }
        }
    }
    void contar_grados(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;j++){
                if(mapa[i][j]=='.'){
                    continue;
                }

                int u = i * m + j;
                int grado = listaAdy.size();
                grados[grado]++;
            }
        }
    }
    int perimetro(){
        int p = 0;
        for(int k = 0; k <=4;k++){
            p+=(4-k)*grados[k];
        }
        return p;
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
    int n,m;
    std::cin>>n>>m;
    Grafo g(n, false);
    for(int i = 0; i < n; i++){
        cin>>g.mapa[i];
    }

    return 0;
}