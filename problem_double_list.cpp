#include <iostream>
struct Node{
    long data;
    Node* next;
    Node* prev;
    Node(long d):data(d), next(nullptr), prev(nullptr){}
};
class List{
    Node* head;
    Node* tail;

    public:
    List(): head(nullptr), tail(nullptr){};

    void Insert(long x){
        Node* New = new Node(x);
        if(head==nullptr){
            head = New;
            tail = New;
        } else {
            head->prev = New;
            New->next = head;
            head = New;
        }
    }
void Delete(long x) {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;

    while (temp != nullptr) {

        if (temp->data == x) {

            // Si es el primero
            if (temp == head) {
                head = temp->next;

                if (head != nullptr) {
                    head->prev = nullptr;
                }
            }
            // Si es el último
            else if (temp == tail) {
                tail = temp->prev;
                tail->next = nullptr;
            }
            // Si está en el medio
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            delete temp;
            return;
        }

        temp = temp->next;
    }
}
void print(){
    Node* actual = head;

    while(actual!=nullptr){
        std::cout << actual->data << " ";
        actual = actual->next;
    }
}
};

int main(){
    List lista;
    int n = 0;
    std::cin>> n;
    for(int i = 0; i< n; i++){
        std::string a = "";
        int x = 0;
        std::cin>>a;
        if(a == "insert"){
            std::cin>>x;
            lista.Insert(x);
        } else if( a == "delete"){
            std::cin>>x;
            lista.Delete(x);
        }
    }
    lista.print();
    return 0;
}