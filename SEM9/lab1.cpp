#include <iostream>
//28 15
//Bonus sobre parcial: 3 puntos
//mañana al medio día - jueves a media noche - De codeforces nivel hard hard hard 
// Si es positivo el balanceo es a la izquierda, y si es negativo es derecha

struct Node{
    Node* izq;
    Node* der;
    int clave;
    int h;
    Node(int cl):izq(nullptr),der(nullptr),clave(cl),h(0){}
};

struct AVL{
    Node* root;
    AVL():root(nullptr){}
    int h(Node* v){
        if(v==nullptr){
            return -1;
        }
        return v->h;
    }
    void actualizar(Node* v){
        v->h=1+std::max(h(v->izq),h(v->der));
    }
    int FB(Node* v){
        return (h(v->izq)-h(v->der));
    }

    Node* rotar_derecha(Node* y){
        Node* x = y->izq;
        y->izq=x->der;
        x->der=y;
        actualizar(y);
        actualizar(x);
        return x;
    }
    Node* rotar_izquierda(Node* y){
        Node* x = y->der;
        y->der=x->izq;
        x->izq=y;
        actualizar(y);
        actualizar(x);
        return x;
    }
    Node* rebalancear(Node* v){
        int fb = FB(v);
        if(fb>1){ 
            if(FB(v->izq)<0){
                v->izq = rotar_izquierda(v->izq); //RL
            }
            return rotar_derecha(v);//LL
        }
        if(fb< (-1)){
            if(FB(v->der)>0){
                v->der=rotar_derecha(v->der);//RL
            }
            return rotar_izquierda(v);//RR
        } 
        return v;
    }

    Node* insertar(Node* v , int k){
        if(v==nullptr){
            Node* nuevo = new Node(k);
            return nuevo;
        }
        if(k<v->clave){
            v->izq=insertar(v->izq,k);
        } else {
            v->der = insertar(v->der,k);
        }
        return rebalancear(v);
    }
    void insertar_aux(int k){
        root = insertar(root,k);
    }
    void impirmir(Node* root){
        if(root == nullptr){
            return;
        }

        impirmir(root->izq);
        std::cout << root->clave << std::endl;
        impirmir(root->der);
    }
    void imprimir_aux(){
        impirmir(root);
    }
    
};
int main(){
    AVL avl;
    avl.insertar_aux(3);
    avl.insertar_aux(20);
    avl.insertar_aux(30);
    avl.insertar_aux(25);
    avl.insertar_aux(10);
    avl.insertar_aux(15);
    avl.imprimir_aux();
    return 0;
}