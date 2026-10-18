#include <iostream>
#include <vector>

struct Node
{
    Node *next;
    long long key;
    int value;
    Node()
    {
    }
    Node(long long _key, int _value)
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
    int hash(long long k)
    {
        return (k%m+m) % m;
    }
    void insert(long long k, int v)
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
    int search(long long k)
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
    void erase(long long k)
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    HashTable map(200003);
    int n = 0;
    long long x = 0;
    std::cin>>n>>x;
    long long suma = 0;
long long contador = 0;

map.insert(0, 1);

for(int i = 0; i < n; i++)
{
    long long num;
    std::cin >> num;

    suma += num;

    // ¿Cuántas veces apareció suma - x?
    int veces = map.search(suma - x);

    if(veces != -1)
    {
        contador += veces;
    }

    // Registrar suma actual
    int actual = map.search(suma);

    if(actual == -1)
    {
        map.insert(suma, 1);
    }
    else
    {
        map.erase(suma);
        map.insert(suma, actual + 1);
    }
}
    std::cout << contador;
    return 0;
}
/*
0| |->
1| |->
2| |->
3| |->
4| |->
5| |->
6| |->






*/
//g++ teo1.cpp -o teo1.exe