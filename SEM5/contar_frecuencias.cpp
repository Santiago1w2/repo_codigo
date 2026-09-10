#include <iostream>
#include <vector>


struct Node{
    int data;
    int key;
    Node* next;
    Node(){}
    Node(int k, int d):data(d),key(k),next(nullptr){}
};


struct T{
    int m = 100;
    int n = 0;
    Node** A = new Node*[m]();
    T(){
    }
    int hash(int k){
        return k % m;
    }

    void insert(int k, int v){
        if((double)n / m >= 0.75){
            increment();
        }
        int idx = hash(k);
        Node* nuevo = new Node(k, v);
        nuevo->next = A[idx];
        A[idx] = nuevo;
        n++;
    }

    int search(int k){
        int idx = hash(k);
        Node* iterador = A[idx];

        while(iterador!=nullptr){
            if(iterador->key==k){
                return iterador->data;
            }
                iterador=iterador->next;
        }
        return -1;
    }
    void erase(int k){
        int idx = hash(k);
        if(A[idx]==nullptr){
            return;
        }

        if(A[idx]->key == k){
            Node* eliminar = A[idx];
            A[idx]=A[idx]->next;
            delete eliminar;
            n--;
            return;

        }
        Node* iterador = A[idx];
            while(iterador->next!=nullptr){
                if(iterador->next->key==k){
                    Node* eliminar = iterador->next;
                    iterador->next=iterador->next->next;
                    delete eliminar;
                    n--;
                    return;
                }
                iterador=iterador->next;
            }
        }

    void increment(){
        int m_new = m*2;
        Node** B=new Node*[m_new]();

        for(int i = 0; i < m;i++){
            Node* temp = A[i];
            while(temp != nullptr){
                Node* next = temp->next;
                int idx = temp->key%m_new;
                temp->next = B[idx];
                B[idx] = temp;
                temp = next;
            }
        }
        delete[] A;
        A = B;
        m = m_new;

    }
    void add(int k){
        int idx = hash(k);
        Node* iterador = A[idx];
        while(iterador != nullptr){
            if(iterador->key == k){
            iterador->data++;
                return;
            }
            iterador = iterador->next;
        }
        insert(k, 1);
    }

};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    T map;

    int n, q;
    std::cin >> n >> q;

    for(int i = 0; i < n; i++) {
        int d;
        std::cin >> d;
        map.add(d);
    }

    for(int i = 0; i < q; i++) {
        int x;
        std::cin >> x;

        int resultado = map.search(x);

        if(resultado != -1) {
            std::cout << resultado << '\n';
        } else {
            std::cout << 0 << '\n';
        }
    }
}