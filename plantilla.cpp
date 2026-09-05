#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
struct DoubleNode {
    T data;
    DoubleNode<T> *next;

    DoubleNode<T> *prev;
    DoubleNode(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template<typename T>
struct SimpleNode {
    T data;
    SimpleNode<T> *next;
    SimpleNode(T data) : data(data), next(nullptr) {}
};

template<typename T>
struct DoubleLinkedList {
    DoubleNode<T> *head = nullptr;
    DoubleNode<T> *tail = nullptr;
    int n = 0;

    bool empty() { return n == 0;}
    int size() { return n; }
    void push_back(T data) {
        DoubleNode<T> *new_node = new DoubleNode<T>(data);
        new_node->prev = tail;
        if (tail != nullptr) {
            tail->next = new_node;
        }else {
            head = new_node;
        }
        tail = new_node;
        n++;
    };
    void print_forward_list() {
        DoubleNode<T> *current = head;
        while (current != nullptr) {
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }
    void print_backward_list() {
        DoubleNode<T> *current = tail;
        while (current != nullptr) {
            std::cout<<current->data<<" ";
            current = current->prev;
        }
    }


};

template<typename T>
struct CircleLinkedList {
    SimpleNode<T> *head = nullptr;
    SimpleNode<T> *tail = nullptr;
    int n = 0;

    bool empty() { return n == 0;}
    int size() { return n; }
    void push_back(T data) {
        SimpleNode<T> *new_node = new SimpleNode<T>(data);
        if (head == nullptr) {
            head = new_node;
            new_node->next = new_node;
        }else {
            new_node->next = head;
            tail->next = new_node;
        }
        tail = new_node;
        n++;
    };
    void print_forward_list() {
        SimpleNode<T> *current = head;
        while (current != nullptr) {
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }
};


void insert(DoubleNode<int> *head, DoubleNode<int> *tail, int x){

}

int main() {
    int n = 0;
    std::cin>> n;
    std::vector<int> s(n);
    for(int i = 0; i < n; i++){
        std::cin>>s[i];
    }
    std::sort(s.begin(), s.end());

    DoubleNode<int> *new_node = new DoubleNode(s[0]);
    DoubleNode<int> *head = new_node;
    DoubleNode<int> *tail= new_node;
    for(int i = 0; i < n; i++){
            DoubleNode<int> *new_node2 = new DoubleNode(s[i]);
            tail->next=new_node2;
            new_node2->prev = head;
            tail = new_node2;
    }
    std::cout << "=================" << std::endl;


    DoubleNode<int> *iterador = head;
    int contador = 0, disponible;
    while(tail != nullptr){
        std::cout << "valor acutal tail: " << tail->data << std::endl;
        if(head== tail){
            contador++;
        }
        contador++;
        disponible = 4 - tail->data;
        while(head->data<=disponible && head!=nullptr && tail!=nullptr){
            disponible = disponible - head->data;
            head=head->next;
        }
        if(head->data>disponible){
            tail=tail->prev;
        }
        
    }
    std::cout << contador << std::endl;

    
    delete iterador;

/*
1 2 3 3 4
dispoible 4-4 = 0
head = 1;
1<=0
head<=disponible

dispoible 4-3 = 1
head = 1;
1<=1
head<=disponible
dispnible = 





*/





    
    








    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}