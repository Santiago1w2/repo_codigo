#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <queue>
using namespace std;

struct Arista {
    long long u, v;
    double w;
};

class Grafo {
public:
    long long n, m;
    bool esDirigido;
    vector<Arista> listaAristas;

    Grafo(long long n, bool dirigido = false) : n(n), m(0), esDirigido(dirigido) {
    }
    void agregarArista(long long u, long long v, double w = 1) {
        listaAristas.push_back({u, v, w});
        m++;
    }

    bool sonAdyacentesListaAristas(long long u, long long v) const {
        for (const Arista& arista : listaAristas) {
            if (arista.u == u && arista.v == v) {
                return true;
            }

            if (!esDirigido && arista.u == v && arista.v == u) {
                return true;
            }
        }

        return false;
    }
    void comprobar(){
        for (const Arista& arista : listaAristas) {
        cout << arista.u << " -> " << arista.v << " | peso: " << arista.w << '\n';
}
    }
};


int main() {
    ifstream file("data.txt");

    if (!file.is_open()) {
        cout << "No se pudo abrir data.txt\n";
        return 1;
    }

    Grafo g(729, true);

    long long u, v;
    double w;

    int contador = 0;
    while (file >> u >> v >> w) {
        g.agregarArista(u,v,w);
        contador++;
    }
    file.close();

    g.comprobar();
    cout << "Los vertices " << 13545515591 << " : " << 12620000350 << ", Son adyacentes? : ";
    if(g.sonAdyacentesListaAristas(13545515591,12620000350)){
        cout <<"SI\n";
    } else {
        cout << "NO\n";
    }
    cout << "Los vertices " << 13506032313 << " : " << 13545515591<< ", Son adyacentes? : ";
    if(g.sonAdyacentesListaAristas(13506032313,13545515591)){
        cout << "SI\n";
    } else {
        cout << "NO\n";
    }

    cout << "Los vertices " << 13545515591 << " : " << 4345082541<< ", Son adyacentes? : ";
    if(g.sonAdyacentesListaAristas(13545515591,4345082541)){
        cout << "SI\n";
    } else {
        cout << "NO\n";
    }
    cout << "cantidad: " << contador;
    return 0;
}