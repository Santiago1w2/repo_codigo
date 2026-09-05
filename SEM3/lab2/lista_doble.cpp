#include <iostream>
template<typename T>
struct DoubleNode{
    T data;
    DoubleNode* next;
    DoubleNode* prev;
    DoubleNode(T a): data(a), next(nullptr), prev(nullptr){}
};

template<typename T>
class DoubleLinkedList{
    DoubleNode<T>* head = nullptr;
    DoubleNode<T>* tail = nullptr;
    int n = 0;
    bool empty(){return n == 0;}
    int size(){return n;}

    public:

void push_back(T data){
    DoubleNode<T>* nuevo = new DoubleNode<T>(data);

    nuevo->prev = tail;

    if(tail == nullptr){
        // Lista vacía
        head = nuevo;
        tail = nuevo;
    } else {
        // Lista con elementos
        tail->next = nuevo;
        tail = nuevo;
    }

    n++;
}
    void print_list(){
        DoubleNode<T>* current=head;
        while(current!=nullptr){
            std::cout << current->data << std::endl;
            current= current->next;
        }
    }
};

int main(){
    DoubleLinkedList<int> *list = new DoubleLinkedList<int>();
    list->push_back(3);
    list->push_back(3);
    list->push_back(3);
    list->push_back(3);
    list->push_back(3);
    list->print_list();
    return 0;
}