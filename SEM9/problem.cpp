#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

const int FALLA = -999999;

struct Nodo {
    int clave;
    int altura;
    int v_der;
    int v_izq;
    Nodo* izq;
    Nodo* der;

    Nodo(int k, int b, int c) : clave(k), altura(0), izq(nullptr), der(nullptr),v_der(c),v_izq(b) {}
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

    Nodo* insertar(Nodo* v, int k, int b, int a) {
        if (v == nullptr) {
            return new Nodo(k,b,a);
        }
        
        if (k < v->clave || v->v_izq == b) {
            v->izq = insertar(v->izq, k,b,a);
        } else if (k > v->clave || v->v_izq == a) {
            v->der = insertar(v->der, k,b,a);
        } else {
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
            } else if (v->der == nullptr) {
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

    int verificar(Nodo* v, long long lo, long long hi) {
        if (v == nullptr) return -1;
        
        if (!(lo < v->clave && v->clave < hi)) return FALLA;
        
        int a = verificar(v->izq, lo, v->clave);
        int b = verificar(v->der, v->clave, hi);
        
        if (a == FALLA || b == FALLA) return FALLA;
        if (v->altura != 1 + max(a, b) || abs(a - b) > 1) return FALLA;
        
        return v->altura;
    }
    void inorder_aux(Nodo* v, std::vector<int>&a){
        if(v!=nullptr){
            inorder_aux(v->izq,a);
            a.push_back(v->clave);
            inorder_aux(v->der,a);
        }
    }
public:
    AVLTree() : raiz(nullptr) {}
    bool verificar_BST(){
        std::vector<int> a;
        inorder_aux(raiz,a);
        for(int i = 1; i < a.size(); i++){
            int temp = a[0];
            if(temp > a[i]){
                return false;
            }
        }
        return true;
    }
    void insertar(int k, int b, int c) {
        raiz = insertar(raiz, k, b, c );
    }

    void eliminar(int k) {
        raiz = eliminar(raiz, k);
    }

    bool esValidoAVL() {
        return verificar(raiz, LLONG_MIN, LLONG_MAX) != FALLA;
    }


};

int main() {
    AVLTree arbol2;
    int t = 0;
    std::cin>>t;
    for(int i = 0; i < t; i++){
        int n = 0;
        std::cin >> n;
        for(int j = 1; j <= n; j++){
            int a = 0, b = 0, c = 0;
            std::cin>>a>>b>>c;
            arbol2.insertar(a,b,c);
        }
        if(arbol2.verificar_BST() && arbol2.esValidoAVL()){
            cout << "AVL" << endl;
        } else if (arbol2.verificar_BST()){
            cout << "BST"<< endl;
        } else if (!arbol2.verificar_BST() && !arbol2.esValidoAVL()){
            cout << "NINGUNO" << endl;
        }
    }
    return 0;
}
