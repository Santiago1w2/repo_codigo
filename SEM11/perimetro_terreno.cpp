
#include <iostream>
#include <vector>
#include <string>

struct Grafo {
    int n;
    int m;

    // grados[k] = cantidad de casillas de tierra con grado k
    std::vector<int> grados = {0, 0, 0, 0, 0};

    std::vector<std::string> mapa;
    std::vector<int> df = {-1, 1, 0, 0};
    std::vector<int> dc = {0, 0, 1, -1};

    std::vector<std::vector<int>> lista_adyacencia;

    Grafo(int _n, int _m): n(_n), m(_m),mapa(n),lista_adyacencia(n * m) {}

    void cargar_mapa() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mapa[i][j] == '.') {
                    continue;
                }
                int u = i * m + j;
                for (int k = 0; k < 4; k++) {
                    int nf = i + df[k];
                    int nc = j + dc[k];
                    if (nf >= 0 && nf < n && nc >= 0 && nc < m && mapa[nf][nc] == '#') {
                        int v = nf * m + nc;
                        lista_adyacencia[u].push_back(v);
                    }
                }
            }
        }
    }

    void contar_grados() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mapa[i][j] == '.') {
                    continue;
                }
                int u = i * m + j;
                int grado = lista_adyacencia[u].size();
                grados[grado]++;
            }
        }
    }

    int perimetro() {
        int P = 0;
        for (int k = 0; k <= 4; k++) {
            P += (4 - k) * grados[k];
        }
        return P;
    }
    void imprimir(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (mapa[i][j]=='.'){
                    continue;
                }
                std::cout << "(" << i << ","<< j << ") :";
                int u = i*m+j;
                for(int v:lista_adyacencia[u]){
                    std::cout << "("<< v/n << "," << v%m << ")" ;
                }
                std::cout << "\n";
            }
        }
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    Grafo grafo(n, m);
    for (int i = 0; i < n; i++) {
        std::cin >> grafo.mapa[i];
    }
    grafo.cargar_mapa();
    grafo.contar_grados();
    std::cout << grafo.perimetro();
    for (int k = 0; k <= 4; k++) {
        std::cout << " " << grafo.grados[k];
    }
    std::cout << "\n";
    grafo.imprimir();
    return 0;
}
