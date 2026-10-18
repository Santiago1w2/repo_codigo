
#include <iostream>
using namespace std;
struct Node {
    Node* prev;
    Node* next;
    int val;
    Node(int va):prev(nullptr), next(nullptr), val(va) {}
};
struct double_linked_list {
    Node* nodos[101];
    int l[101], r[101];
    int n;
    double_linked_list(int a) : n(a) {
        for (int i = 1; i <= n; i++) {
            nodos[i] = new Node(i);
        }
    }

    void unir() {
        Node* head = nullptr;
        Node* tail = nullptr;
        for (int i = 1; i <= n; i++) {
            if (l[i] == 0) {
                Node* inicio = nodos[i];
                if (head== nullptr) {
                    head = inicio;
                } else {
                    tail->next = inicio;
                    inicio->prev = tail;
                }
                tail = inicio;
                while (tail->next != nullptr) {
                    tail = tail->next;
                }
            }
        }
    }
    void imprimir() {
        for (int i = 1; i <= n; i++) {
            int l = 0;
            int r = 0;
            if (nodos[i]->prev != nullptr)
                l = nodos[i]->prev->val;
            if (nodos[i]->next != nullptr)
                r = nodos[i]->next->val;
            cout << l << " " << r << "\n";
        }
    }
};

int main() {
    int n;
    cin >> n;

    double_linked_list list(n);
    for(int i = 1; i <= n; i++) {
        cin >> list.l[i] >> list.r[i];
    }
    for(int i = 1; i <= n; i++) {
        if (list.l[i] != 0)
            list.nodos[i]->prev = list.nodos[list.l[i]];
        if (list.r[i] != 0)
            list.nodos[i]->next = list.nodos[list.r[i]];
    }
    list.unir();
    list.imprimir();

    return 0;
}