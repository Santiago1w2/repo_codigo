
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

struct Nodo {
    int i, a;
    int prioridad;
    int tam, maxA;
    Nodo *izq, *der;

    Nodo(int i, int a) {
        this->i = i;
        this->a = a;
        prioridad = rand();
        tam = 1;
        maxA = a;
        izq = der = nullptr;
    }
};
struct Tree {
    Nodo* raiz;
    Tree() {
        raiz = nullptr;
    }
    int tam(Nodo* t) {
        if (t == nullptr) return 0;
        return t->tam;
    }
    int maximo(Nodo* t) {
        if (t == nullptr) return -1;
        return t->maxA;
    }
    void actualizar(Nodo* t) {
        if (t == nullptr) return;
        t->tam = 1 + tam(t->izq) + tam(t->der);
        t->maxA = t->a;
        if (maximo(t->izq) > t->maxA)
            t->maxA = maximo(t->izq);
        if (maximo(t->der) > t->maxA)
            t->maxA = maximo(t->der);
    }
    void dividir(Nodo* t, int k, Nodo*& izq, Nodo*& der) {
        if (t == nullptr) {
            izq = der = nullptr;
            return;
        }
        if (tam(t->izq) >= k) {
            dividir(t->izq, k, izq, t->izq);
            der = t;
            actualizar(der);
        } else {
            dividir(t->der, k - tam(t->izq) - 1,
                    t->der, der);
            izq = t;
            actualizar(izq);
        }
    }
    Nodo* unir(Nodo* izq, Nodo* der) {
        if (izq == nullptr) return der;
        if (der == nullptr) return izq;

        if (izq->prioridad > der->prioridad) {
            izq->der = unir(izq->der, der);
            actualizar(izq);
            return izq;
        } else {
            der->izq = unir(izq, der->izq);
            actualizar(der);
            return der;
        }
    }
    int ultimoMayorIgual(Nodo* t, int x) {
        if (t == nullptr || t->maxA < x)
            return -1;
        int izquierda = tam(t->izq);
        if (maximo(t->der) >= x)
            return izquierda + 1 +
                ultimoMayorIgual(t->der, x);
        if (t->a >= x)
            return izquierda;
        return ultimoMayorIgual(t->izq, x);
    }
    void insertar(int id, int a, int c) {
        int n = tam(raiz);
        int ultimo = ultimoMayorIgual(raiz, a);
        int avanzar;
        if (ultimo == -1)
            avanzar = n;
        else
            avanzar = n - 1 - ultimo;
        if (avanzar > c)
            avanzar = c;
        int posicion = n - avanzar;
        Nodo *izq, *der;
        dividir(raiz, posicion, izq, der);
        Nodo* nuevo = new Nodo(id, a);
        raiz = unir(unir(izq, nuevo), der);
    }
    void imprimir(Nodo* t) {
        if (t == nullptr) return;
        imprimir(t->izq);
        cout << t->i << " ";
        imprimir(t->der);
    }
    void imprimir() {
        imprimir(raiz);
        cout << "\n";
    }
};

int main() {
    srand(time(nullptr));

    int n;
    cin >> n;

    Tree cola;

    for (int i = 1; i <= n; i++) {
        int a, c;
        cin >> a >> c;

        cola.insertar(i, a, c);
    }

    cola.imprimir();

    return 0;
}
