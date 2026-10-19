
#include <iostream>
#include <algorithm>
using namespace std;

struct Nodo {
    int clave;
    int altura;
    int tam;
    Nodo* izq;
    Nodo* der;

    Nodo(int k) : clave(k), altura(0), tam(1),izq(nullptr), der(nullptr) {}
};

class AVLTree {
private:
    Nodo* raiz;

    int h(Nodo* v) {
        if (v == nullptr) return -1;
        return v->altura;
    }

    int tamano(Nodo* v) {
        if (v == nullptr) return 0;
        return v->tam;
    }

    void actualizar(Nodo* v) {
        if (v != nullptr) {
            v->altura = 1 + max(h(v->izq), h(v->der));
            v->tam = 1 + tamano(v->izq) + tamano(v->der);
        }
    }

    int FB(Nodo* v) {
        if (v == nullptr) return 0;
        return h(v->izq) - h(v->der);
    }

    Nodo* rotarDerecha(Nodo* y) {
        Nodo* x = y->izq;
        y->izq = x->der;
        x->der = y;

        actualizar(y);
        actualizar(x);

        return x;
    }

    Nodo* rotarIzquierda(Nodo* x) {
        Nodo* y = x->der;
        x->der = y->izq;
        y->izq = x;

        actualizar(x);
        actualizar(y);

        return y;
    }

    Nodo* rebalancear(Nodo* v) {
        if (v == nullptr) return nullptr;

        actualizar(v);

        if (FB(v) > 1) {
            if (FB(v->izq) < 0) {
                v->izq = rotarIzquierda(v->izq);
            }
            return rotarDerecha(v);
        }

        if (FB(v) < -1) {
            if (FB(v->der) > 0) {
                v->der = rotarDerecha(v->der);
            }
            return rotarIzquierda(v);
        }

        return v;
    }

    Nodo* insertar(Nodo* v, int k) {
        if (v == nullptr) {
            return new Nodo(k);
        }

        if (k < v->clave) {
            v->izq = insertar(v->izq, k);
        } else if (k > v->clave) {
            v->der = insertar(v->der, k);
        } else {
            return v;
        }

        return rebalancear(v);
    }

    Nodo* minimo(Nodo* v) {
        while (v->izq != nullptr) {
            v = v->izq;
        }
        return v;
    }

    Nodo* eliminar(Nodo* v, int k) {
        if (v == nullptr) return nullptr;
        if (k < v->clave) {
            v->izq = eliminar(v->izq, k);
        } else if (k > v->clave) {
            v->der = eliminar(v->der, k);
        } else {
            if (v->izq == nullptr) {
                Nodo* temp = v->der;
                delete v;
                return temp;
            }
            if (v->der == nullptr) {
                Nodo* temp = v->izq;
                delete v;
                return temp;
            }
            Nodo* s = minimo(v->der);
            v->clave = s->clave;
            v->der = eliminar(v->der, s->clave);
        }
        return rebalancear(v);
    }

    int kesimo(Nodo* v, int k) {
        int izquierda = tamano(v->izq);
        if (k == izquierda + 1) {
            return v->clave;
        }
        if (k <= izquierda) {
            return kesimo(v->izq, k);
        }
        return kesimo(v->der, k - izquierda - 1);
    }

public:
    AVLTree() : raiz(nullptr) {}

    void insertar(int k) {
        raiz = insertar(raiz, k);
    }

    void eliminar(int k) {
        raiz = eliminar(raiz, k);
    }

    int kesimo(int k) {
        return kesimo(raiz, k);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    AVLTree arbol;
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            arbol.insertar(x);
        } else if (t == 2) {
            arbol.eliminar(x);
        } else {
            cout << arbol.kesimo(x) << '\n';
        }
    }

    return 0;
}
