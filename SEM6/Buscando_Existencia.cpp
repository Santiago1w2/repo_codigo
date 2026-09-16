#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

struct Node {
    Node* izq;
    Node* der;
    Node* father;
    int data;

    Node(int d)
        : der(nullptr), izq(nullptr), father(nullptr), data(d) {}
};

class binary_tree {
    Node* root;
    Node* buscar(Node* root, int a) {
        if(root == nullptr || a == root->data) {
            return root;
        }
        if(a < root->data) {
            return buscar(root->izq, a);
        }
        return buscar(root->der, a);
    }
Node* maximo(Node* root) {

    if (root == nullptr)
        return nullptr;

    while (root->der != nullptr) {
        root = root->der;
    }

    return root;
}
    void InOrder(Node* root) {
        if(root == nullptr) {
            return;
        }
        InOrder(root->izq);
        std::cout << root->data << " ";
        InOrder(root->der);
    }

    void PreOrder(Node* root) {
        if(root == nullptr) {
            return;
        }
        std::cout << root->data << " ";
        PreOrder(root->izq);
        PreOrder(root->der);
    }
    
    void PostOrder(Node* root) {
        if(root == nullptr) {
            return;
        }
        PostOrder(root->izq);
        PostOrder(root->der);
        std::cout << root->data << " ";
    }

    void insertar(Node*& root, int k) {
        Node* y = nullptr;
        Node* x = root;
        while(x != nullptr) {
            y = x;
            if(k < x->data) {
                x = x->izq;
            }
            else {
                x = x->der;
            }
        }
        Node* z = new Node(k);
        z->father = y;
        if(y == nullptr) {
            root = z;
        }
        else if(k < y->data) {
            y->izq = z;
        }
        else {
            y->der = z;
        }
    }
    int altura(Node* root){
        if(root==nullptr){
            return -1;
        }
        return 1 + std::max(altura(root->izq),altura(root->der));
    }
    int size(Node* root) {
        if (root == nullptr)
            return 0;
        return 1 + size(root->izq) + size(root->der);
    }

    int nivel(Node* root, int valor, int nivelActual = 0) {
        if (root == nullptr)
            return -1;
        if (root->data == valor)
            return nivelActual;
        if (valor < root->data)
            return nivel(root->izq, valor, nivelActual + 1);
        return nivel(root->der, valor, nivelActual + 1);
    }

    bool esLleno(Node* root) {
        if (root == nullptr)
            return true;
        if (root->izq == nullptr && root->der == nullptr)
            return true;
        if (root->izq != nullptr && root->der != nullptr)
            return esLleno(root->izq) && esLleno(root->der);
        return false;
    }
    bool esCompleto(Node* root) {
        if (root == nullptr)
            return true;
        std::queue<Node*> q;
        q.push(root);
        bool encontreVacio = false;
        while (!q.empty()) {
            Node* actual = q.front();
            q.pop();
            if (actual == nullptr) {
                encontreVacio = true;
            }
            else {
                if (encontreVacio)
                    return false;
                q.push(actual->izq);
                q.push(actual->der);
            }
        }
        return true;
    }
bool esPerfecto(Node* root) {
    if (root == nullptr)
        return true;

    int h = altura(root);
    int cantidad = size(root);

    int esperado = (1 << (h + 1)) - 1;

    return cantidad == esperado;
}

bool esDegenerado(Node* root) {
    if (root == nullptr)
        return true;
    if (root->izq != nullptr &&
        root->der != nullptr)
        return false;
    if (root->izq != nullptr)
        return esDegenerado(root->izq);
    if (root->der != nullptr)
        return esDegenerado(root->der);
    return true;
}
Node* predecesor(Node* root, Node* nodo) {

    if (nodo == nullptr)
        return nullptr;

    if (nodo->izq != nullptr) {
        return maximo(nodo->izq);
    }

    Node* pred = nullptr;
    Node* actual = root;

    while (actual != nullptr) {

        if (nodo->data > actual->data) {

            pred = actual;
            actual = actual->der;
        }

        else if (nodo->data < actual->data) {

            actual = actual->izq;
        }

        else {
            break;
        }
    }

    return pred;
}
Node* eliminar(Node* root, int valor) {

    // No encontramos el nodo
    if (root == nullptr)
        return nullptr;


    // Buscar por izquierda
    if (valor < root->data) {

        root->izq = eliminar(root->izq, valor);
    }


    // Buscar por derecha
    else if (valor > root->data) {

        root->der = eliminar(root->der, valor);
    }


    // Encontramos el nodo
    else {

        // CASO 1:
        // No tiene hijos
        if (root->izq == nullptr &&
            root->der == nullptr) {

            delete root;
            return nullptr;
        }


        // CASO 2:
        // Solo tiene hijo derecho
        else if (root->izq == nullptr) {

            Node* temp = root->der;

            delete root;

            return temp;
        }


        // CASO 2:
        // Solo tiene hijo izquierdo
        else if (root->der == nullptr) {

            Node* temp = root->izq;

            delete root;

            return temp;
        }


        // CASO 3:
        // Tiene DOS hijos
        else {

            Node* pred = maximo(root->izq);

            root->data = pred->data;

            root->izq =
                eliminar(root->izq, pred->data);
        }
    }

    return root;
}
public:

    binary_tree() : root(nullptr) {}

    bool buscar_aux(int k) {
        return buscar(root, k) != nullptr;
    }
    int size(){
        return size(root);
    }
    int altura_aux(){
        return altura(root);
    }

    void insertar_aux(int k) {
        insertar(root, k);
    }

    void InOrder_aux() {
        InOrder(root);
    }
    void PreOrder_aux() {
        PreOrder(root);
    }
    void PostOrder_aux() {
        PostOrder(root);
    }
    
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    binary_tree arbol;
    int n = 0, q = 0;
    std::cin>>n>>q;
    for(int i = 0; i < n; i++){
        int c = 0;
        std::cin>>c;
        arbol.insertar_aux(c);
    }
    for(int i = 0; i < q; i++){
        int c = 0;
        std::cin>>c;
        if(arbol.buscar_aux(c)){
            std::cout << "SI" << "\n";
        } else {
            std::cout << "NO" << "\n";
        }
    }
}