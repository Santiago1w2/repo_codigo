#include <iostream>
#include <vector>
#include <queue>

struct Node
{
    Node *next;
    int key;
    int value;
    Node()
    {
    }
    Node(int _key, int _value)
    {
        next = nullptr;
        key = _key;
        value = _value;
    }
};
struct HashTable
{
    int m;
    int n;
    Node **A;
    HashTable(int _m)
    {
        m = _m;
        n=0;
        A = new Node *[m];
        for (int i = 0; i < m; i++)
            A[i] = nullptr;
    }
    int hash(int k)
    {
        return (k%m+m) % m;
    }
    void insert(int k, int v)
    {
        if((double)n/m>=0.75){
            rehashing();
        }
        Node *new_node = new Node(k, v);
        int p = hash(k);
        new_node->next=A[p];
        A[p]=new_node;
        n++;
    }
    int search(int k)
    {
        int p = hash(k);
        if (A[p] == nullptr)
        {
            return -1;
        }
        else
        {
            Node *temp = A[p];
            while (temp != nullptr)
            {
                if (temp->key == k)
                {
                    return temp->value;
                }
                temp = temp->next;
            }
            return -1;
        }
    }
    void erase(int k)
    {
        int p = hash(k);
        Node *temp = A[p];
        Node *prev = nullptr;
        while (temp != nullptr)
        {
            if (temp->key == k)
            {
                if (prev == nullptr)
                {
                    A[p] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                n--;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    void rehashing()
    {
        int old_m = m;
        m = 2 * m;
        Node **A_old = A;
        Node **A_new = new Node *[m];
        for (int i = 0; i < m; i++)
        {
            A_new[i] = nullptr;
        }
        for (int i = 0; i < old_m; i++)
        {
            Node *temp = A_old[i];
            while (temp != nullptr)
            {
                Node *next = temp->next;
                int idx = hash(temp->key);
                temp->next = A_new[idx];
                A_new[idx] = temp;
                temp = next;
            }
        }
        delete[] A_old;
        A = A_new;
    }
};

int main(){
    HashTable map(100);
    std::queue<int> cola;
    int n = 0;
    std::cin>>n;
    for(int i = 0; i < n; i ++){
        int c = 0;
        std::cin>>c;
        if(map.search(c)!=-1){
            int temp = map.search(c);
            map.erase(c);
            map.insert(c,temp+1);
        } else {
            map.insert(c,1);
            cola.push(c);
        } 
    }
    while(!cola.empty()){
        int rept = map.search(cola.front());
        if(rept==1){
            std::cout << cola.front();
            return 0;
        }
        cola.pop();
    }
    std::cout << -1;
    return 0;
}