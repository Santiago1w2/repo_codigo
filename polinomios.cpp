#include <iostream>

struct Node{
    int x;
    int exp;
    Node* next;
    Node(int x, int e):next(nullptr),x(x),exp(e){}
};


struct linked_list{
    Node* head;
    Node* tail;
    int len = 0;
    linked_list():head(nullptr), tail(nullptr),len(0){}

    void push_front(int x,int e){
        Node* nuevo = new Node(x,e);
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
    void push_back(int x, int e){
        Node* nuevo = new Node(x,e);
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
            std::cout << iterador->exp << " "<< iterador->x << std::endl;
            iterador = iterador->next;
        }
    }
    bool empty(){
        return len == 0;
    }
};



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    linked_list P;
    linked_list Q;
    int n1 = 0;
    std::cin>>n1;
    for(int i = 0; i < n1; i++){
        int e = 0, c = 0;
        std::cin>>e>>c;
        P.push_back(c,e);
    }
    int n2 = 0;
    std::cin>>n2;
    for(int i = 0; i < n2; i++){
        int e = 0, c = 0;
        std::cin>>e>>c;
        Q.push_back(c,e);
    }
    linked_list m;
    while(!P.empty() && !Q.empty()){
        if(P.head->exp == Q.head->exp ){
            if((Q.head->x+P.head->x)!=0){
                m.push_back((Q.head->x+P.head->x),P.head->exp);
            }
            
            P.pop_front();
            Q.pop_front();
        } else{
            if(P.head->exp < Q.head->exp){
                m.push_back((P.head->x),P.head->exp);
                P.pop_front();
            } else if (P.head->exp > Q.head->exp){
                m.push_back((Q.head->x),Q.head->exp);
                Q.pop_front();
            }
        }
    }

    if(P.empty()){
        while(!Q.empty()){
            m.push_back(Q.head->x, Q.head->exp);
            Q.pop_front();
        }
    } else {
        while(!P.empty()){
            m.push_back(P.head->x, P.head->exp);
            P.pop_front();
        }        
    }
    std::cout<<m.len << std::endl;

    m.print();

    return 0;
}