#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 200000;

struct Nodo {
    int clave;
    int altura;
    int freq;
    Nodo* izq;
    Nodo* der;

    Nodo(int k) : clave(k), altura(0), freq(1),izq(nullptr), der(nullptr) {}
};

class AVLTree {
private:
    Nodo* raiz;

    int h(Nodo* v) {
        return v == nullptr ? -1 : v->altura;
    }

    void actualizar(Nodo* v) {
        if (v != nullptr) {
            v->altura = 1 + max(h(v->izq), h(v->der));
        }
    }

    int FB(Nodo* v) {
        return v == nullptr ? 0 : h(v->izq) - h(v->der);
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
        if (v == nullptr) return new Nodo(k);

        if (k < v->clave) {
            v->izq = insertar(v->izq, k);
        } else if (k > v->clave) {
            v->der = insertar(v->der, k);
        } else {
            v->freq++;
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
            if (v->freq > 1) {
                v->freq--;
                return v;
            }

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
            v->freq = s->freq;
            s->freq = 1;
            v->der = eliminar(v->der, s->clave);
        }

        return rebalancear(v);
    }

public:
    AVLTree() : raiz(nullptr) {}

    void insertar(int k) {
        raiz = insertar(raiz, k);
    }

    void eliminar(int k) {
        raiz = eliminar(raiz, k);
    }
};

class SegmentTree {
private:
    vector<int> ocupados;

    void actualizar(int nodo, int izq, int der,
                    int pos, int valor) {
        if (izq == der) {
            ocupados[nodo] = valor;
            return;
        }

        int medio = (izq + der) / 2;

        if (pos <= medio) {
            actualizar(nodo * 2, izq, medio, pos, valor);
        } else {
            actualizar(nodo * 2 + 1, medio + 1, der, pos, valor);
        }

        ocupados[nodo] = ocupados[nodo * 2]
                       + ocupados[nodo * 2 + 1];
    }

    int buscar(int nodo, int izq, int der) {
        if (izq == der) return izq;

        int medio = (izq + der) / 2;
        int tamIzq = medio - izq + 1;

        if (ocupados[nodo * 2] < tamIzq) {
            return buscar(nodo * 2, izq, medio);
        }

        return buscar(nodo * 2 + 1, medio + 1, der);
    }

public:
    SegmentTree() : ocupados(4 * (MAXN + 1), 0) {}

    void actualizar(int pos, int valor) {
        actualizar(1, 0, MAXN, pos, valor);
    }

    int menor_libre() {
        if (ocupados[1] == MAXN + 1) {
            return MAXN + 1;
        }

        return buscar(1, 0, MAXN);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    AVLTree arbol;
    SegmentTree seg;
    vector<int> freq(MAXN + 1, 0);

    int q;
    cin >> q;

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;

            arbol.insertar(x);

            freq[x]++;
            if (freq[x] == 1) {
                seg.actualizar(x, 1);
            }
        } else if (op == 2) {
            int x;
            cin >> x;

            arbol.eliminar(x);

            freq[x]--;
            if (freq[x] == 0) {
                seg.actualizar(x, 0);
            }
        } else {
            cout << seg.menor_libre() << '\n';
        }
    }

    return 0;
}