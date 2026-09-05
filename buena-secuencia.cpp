#include <iostream>
#include <algorithm>
#include <vector>
struct Nodo {
    int dato;
    Nodo* anterior;
    Nodo* siguiente;

    Nodo(int valor) {
        dato = valor;
        anterior = nullptr;
        siguiente = nullptr;
    }
};
class Lista {
private:
    Nodo* head;
    Nodo* tail;

public:
    Lista() {
        head = nullptr;
        tail = nullptr;
    }
    void push(long dat){
        Nodo* nuevo = new Nodo(dat);
        if(head == nullptr){
            head = nuevo;
            tail = nuevo;
            return;
        }
        if(head->dato >= dat){
            nuevo->siguiente = head;
            head->anterior = nuevo;
            head = nuevo;
            return;
        }
        if(tail->dato <= dat){
            nuevo->anterior = tail;
            head->siguiente = nuevo;
            tail=nuevo;
            return;
        }

        Nodo* temporal = head;
        while (temporal->dato < dat) {
        temporal = temporal->siguiente;
    }
    nuevo->siguiente = temporal;
    nuevo->anterior = temporal->anterior;

    temporal->anterior->siguiente = nuevo;
    temporal->anterior = nuevo;
    }

    void imprimirAdelante() {
        Nodo* actual = head;

        while (actual != nullptr) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
    }
    int verificar(int N){
        
        int eliminar = 0;
        Nodo* i = head;
        while(i!=nullptr){
            Nodo* j = head;
            int contador = 0;
            while(j!=nullptr){
                if(i->dato == j->dato){
                    contador++;
                }
                j = j->siguiente;
            }
            std::cout << "Contador: " << contador <<std::endl;
            if(i->dato!=contador){
                eliminar+=(contador - i->dato);
            }
            std::cout << "eliminar: " << eliminar<<std::endl;
            i=i->siguiente;
        }
        return eliminar;
    }

};

int main(){
    Lista linked_list;
    int N = 0;
    std::cin>>N;
    std::vector<long> cadena(N);
    for(int i = 0; i < N; i++){
        long a = 0;
        std::cin>>a;
        linked_list.push(a);
    }
    //linked_list.imprimirAdelante();
    int d = linked_list.verificar(N);
    std::cout<< d;
    return 0;
}