#include <iostream>

struct Node{
    int data;
    Node* next;
    Node(int d):next(nullptr),data(d){}
};


struct linked_list{
    Node* head;
    int len = 0;
    linked_list():head(nullptr),len(0){}

    void push_front(int x){
        Node* nuevo = new Node(x);
        if(head==nullptr){
            head = nuevo;
        }
        head->next= nuevo;
        len++;
    }
    void push_back(int x){
        Node* nuevo = new Node(x);
        if(head == nullptr){
            head = nuevo;
        }

        Node* iterador = head;
        while(iterador != nullptr){
            if(iterador->next == nullptr){
                iterador->next = nuevo;
            }
            iterador = iterador->next;
        }
        len++;
    }

    int size(){
        return len;
    }
    void pop_back(){
        if(head==nullptr){
            return;
        }
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            len--;
        }

        Node* iterador = head;
        while(iterador->next->next !=nullptr){
            iterador=iterador->next;
        }
        Node* eliminar = iterador->next;
        iterador->next = nullptr;
        delete eliminar;
        len--;
    }
    void pop_front(){
        if(head==nullptr){
            return;
        }
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            len--;
        }

        Node* guardar = head->next;
        Node* eliminar = head;
        head = guardar;
        delete eliminar;
        len--;
    }
};


int main(){
    return 0;
}

//g++ linked_list.cpp -o linked_list.exe