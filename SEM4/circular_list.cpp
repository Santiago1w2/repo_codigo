#include <iostream>
struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

struct CircularList {

    Node* head;
    Node* tail;
    int len;

    CircularList(): head(nullptr), tail(nullptr), len(0) {}

void push_back(int x) {

    Node* nuevo = new Node(x);

    if (head == nullptr) {
        head = nuevo;
        tail = nuevo;

        nuevo->next = head;
        len++;
        return;
    }

    tail->next = nuevo;
    tail = nuevo;

    tail->next = head;

    len++;
}
void push_front(int x) {

    Node* nuevo = new Node(x);

    if (head == nullptr) {
        head = nuevo;
        tail = nuevo;

        nuevo->next = head;
        len++;
        return;
    }

    nuevo->next = head;
    head = nuevo;

    tail->next = head;

    len++;
}
void print() {

    if (head == nullptr)
        return;

    Node* iterador = head;

    do {
        std::cout << iterador->data << " ";
        iterador = iterador->next;

    } while (iterador != head);
}
void pop_back(){

    if(head == nullptr){
        return;
    }

    // Un solo nodo
    if(head == tail){
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

    tail->next = head;

    len--;
}
void resolver(int n){
    CircularList list;
    for(int i = 1; i < n+1; i++){
        this->push_back(i);
    }
    Node* iterador = head;
    for(int i = 0; i < len;i++){
        if(iterador->data%2==0){
            list.push_back(iterador->data);
        }
        iterador=iterador->next;
    }
    iterador = head;

    for(int i = 0; i < len;i++){
        if(iterador->data%2!=0){
            list.push_back(iterador->data);
        }
        iterador=iterador->next;
    }
    list.print();

}

};


int main(){
    CircularList principal_list;
    int n = 0;
    std::cin>>n;
    principal_list.resolver(n);

    return 0;
}