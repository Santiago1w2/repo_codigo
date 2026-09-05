#include <iostream>
//siguiente: guarda la direcicon al que apunta
//&siguiente: direcicon del mismo puntero
template<typename T>
struct Nodo{
    T dato;
    Nodo* siguiente;
    Nodo(T d): dato(d), siguiente(nullptr){}
};

template<typename T>
class linked_list{
    Nodo<T>* head;
    Nodo<T>* tail;
    public:
    linked_list():head(nullptr), tail(nullptr){}
    void push_front(T a){
        Nodo<T>* nuevo(a);

    }

};
int main(){
    return 0;
}