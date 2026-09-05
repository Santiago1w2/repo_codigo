#include <iostream>
struct Double_Node{
    int data;
    Double_Node* next;
    Double_Node* prev;
    
    Double_Node(int d):data(d),next(nullptr),prev(nullptr){}
};
struct double_linked_list{
    Double_Node* head;
    Double_Node* tail;
    int len;
    double_linked_list():head(nullptr), tail(nullptr),len(0){}

    void push_front(int x){
        Double_Node* nuevo = new Double_Node(x);
        if(head==nullptr){
            head = nuevo;
            tail=nuevo;
        }
        nuevo->next=head;
        head->prev = nuevo;
        head=nuevo;
        len++;
    }
    void push_back(int x){
        Double_Node* nuevo = new Double_Node(x);
        if(head==nullptr){
            head = nuevo;
            tail =nuevo;
        }
        nuevo->prev=tail;
        tail->next = nuevo;
        tail = nuevo;
        len++;
    }

    void pop_front(){
        if(head==nullptr){
            return;
        }
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            tail = nullptr;
            len--;
        }

        Double_Node* eliminar = head;
        head = head->next;
        head->prev = nullptr;
        delete eliminar;
        len--;

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
        Double_Node* eliminar = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete eliminar;
        len--;
    }

};
int main(){
    return 0;
}

//g++ double_linked_list.cpp -o double_linked_list.exe