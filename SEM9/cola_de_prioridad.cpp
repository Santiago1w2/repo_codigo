#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int FALLA = -999999;

struct Nodo {
    int clave;
    int altura;
    int freq;
    Nodo* izq;
    Nodo* der;

    Nodo(int k) : clave(k), altura(0), izq(nullptr), der(nullptr), freq(1) {}
};

class AVLTree {
private:
    Nodo* raiz;

    int h(Nodo* v) {
        if (v == nullptr) return -1;
        return v->altura;
    }

    void actualizar(Nodo* v) {
        if (v != nullptr) {
            v->altura = 1 + max(h(v->izq), h(v->der));
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
            v->freq=v->freq+1;
            return v;
        }
        
        return rebalancear(v);
    }

    Nodo* minimo(Nodo* v) {
        Nodo* actual = v;
        while (actual && actual->izq != nullptr) {
            actual = actual->izq;
        }
        return actual;
    }
    Nodo* maximo(Nodo* v){
        Nodo* actual = v;
        while(actual && actual->der!=nullptr){
            actual = actual->der;
        }
        return actual;
    }

    Nodo* eliminar(Nodo* v, int k) {
        if (v == nullptr) return nullptr;
        
        if (k < v->clave) {
            v->izq = eliminar(v->izq, k);
        } else if (k > v->clave) {
            v->der = eliminar(v->der, k);
        } else {
            if(v->freq == 1){
                    if (v->izq == nullptr) {
                    Nodo* temp = v->der;
                    delete v;
                    return temp;
                } else if (v->der == nullptr) {
                    Nodo* temp = v->izq;
                    delete v;
                    return temp;
                }
                Nodo* s = minimo(v->der);
                v->clave = s->clave;
                v->freq=s->freq;
                s->freq=1;
                v->der = eliminar(v->der, s->clave);
            } else {
                v->freq--;
                return v;
            }
        }
        return rebalancear(v);
    }

    int verificar(Nodo* v, long long lo, long long hi) {
        if (v == nullptr) return -1;
        
        if (!(lo < v->clave && v->clave < hi)) return FALLA;
        
        int a = verificar(v->izq, lo, v->clave);
        int b = verificar(v->der, v->clave, hi);
        
        if (a == FALLA || b == FALLA) return FALLA;
        if (v->altura != 1 + max(a, b) || abs(a - b) > 1) return FALLA;
        
        return v->altura;
    }
    void inorden(Nodo* v) {
        if (v != nullptr) {
            inorden(v->izq);
            cout << v->clave << " ";
            inorden(v->der);
        }
    }
public:
    AVLTree() : raiz(nullptr) {}
    Nodo* getRaiz(){
        return raiz;
    }
    void insertar(int k) {
        raiz = insertar(raiz, k);
    }

    void eliminar(int k) {
        raiz = eliminar(raiz, k);
    }
    int maximo_aux(){
        Nodo* max_aux=maximo(raiz);
        return max_aux->clave;
    }
    int minimo_aux(){
        Nodo* mino_aux=minimo(raiz);
        return mino_aux->clave;
    }
    bool esValidoAVL() {
        return verificar(raiz, LLONG_MIN, LLONG_MAX) != FALLA;
    }

    void imprimir() {
        inorden(raiz);
        cout << endl;
    }
};

int main() {
    AVLTree arbol;
    int q=0;
    std::cin>>q;
    for(int i = 0; i < q; i++){
        int op;
        std::cin>>op;
        if(op==1){
            int k;
            std::cin>>k;
            arbol.insertar(k);
        } else if(op==2){
            if(arbol.getRaiz()!=nullptr){
                int minomo_tree=arbol.minimo_aux();
                std::cout << minomo_tree<<"\n";
                arbol.eliminar(minomo_tree);
            } else{
                std::cout << "VACIA\n";
            }

        } else{
            if(arbol.getRaiz()!=nullptr){
                int max_tree = arbol.maximo_aux();
                std::cout << max_tree<<"\n";
                arbol.eliminar(max_tree);
            } else{
                std::cout << "VACIA\n";
            }
        }
    }
    return 0;
}