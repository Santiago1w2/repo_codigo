#include <iostream>

struct Node{
    int data;
    Node* next;
    Node(int d):data(d),next(nullptr){}
};

struct linked_list{
    Node* head;
    Node* tail;
    int len = 0;
    linked_list():head(nullptr), tail(nullptr),len(0){}

    void push_front(int a){
        Node* nuevo = new Node(a);
        if(head==nullptr){
            head = nuevo;
            tail = nuevo;
            len++;
            return;
        }
        nuevo->next = head;
        head = nuevo;
        len++;
    }
    void push_back(int a){
        Node* nuevo = new Node(a);
        if(head == nullptr){
            head = nuevo;
            tail = nuevo;
            len++;
            return;
        }
        tail->next =nuevo;
        tail = nuevo;
        len++;
    }
    void pop_back(){

        if(head==nullptr){

            return;
        }

        if(head->next == nullptr){

            delete head;

            head = nullptr;
            tail = nullptr;

            len--;

            return;
        }

        Node* iterador = head;

        while(iterador->next != tail){

            iterador = iterador->next;
        }

        delete tail;

        tail = iterador;

        tail->next = nullptr;

        len--;
    }

    int size(){
        return len;
    }
    void pop_front(){
        if(head==nullptr){
            return;
        }
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            len--;
            return;
        }

        Node* guardar = head->next;
        Node* eliminar = head;
        head = guardar;
        delete eliminar;
        len--;
    }

    void print(){
        Node* iterador = head;

        while(iterador != nullptr){
            if(iterador!=head){
                std::cout << " ";
            }
            std::cout << iterador->data;
            iterador=iterador->next;
        }
    }
    bool empty(){
        return len == 0;
    }
    void eliminar(Node* nodo){
        if(nodo == nullptr || nodo->next == nullptr){
            return;
        }
        // Solo necesitamos el nodo indicado, sin buscar su anterior.
        Node* siguiente = nodo->next;
        nodo->data = siguiente->data;
        nodo->next = siguiente->next;
        if(tail == siguiente){
            tail = nodo;
        }
        delete siguiente;
        len--;
    }
};



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    linked_list list;
    int n = 0, i = 0;
    std::cin>>n>>i;
    Node* objetivo = nullptr;
    for(int j = 1; j <= n; j++){
        int a;
        std::cin>>a;
        list.push_back(a);
        if(j == i){
            objetivo = list.tail;
        }
    }
    list.eliminar(objetivo);
    list.print();
    std::cout << '\n';
    return 0;
}

//g++ linked_list.cpp -o linked_list.exe

