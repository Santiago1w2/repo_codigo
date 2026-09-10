#include <iostream>
using namespace std;
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
    Node **A;
    HashTable(int _m)
    {
        m = _m;
        A = new Node *[m];
        for (int i = 0; i < m; i++)
            A[i] = nullptr;
    }
    int hash(int k)
    {
        return k % m;
    }
    void insert(int k, int v)
    {
        Node *new_node = new Node(k, v);
        int p = hash(k);
        if (A[p] == nullptr)
        {
            A[p] = new_node;
        }
        else
        {
            Node *temp = A[p];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
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
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        HashTable map(50);
        int contador = 0;
        for(int i = 0; i < jewels.size(); i++){
            char busqueda = jewels[i];
            map.insert(busqueda,0);
            for(int j = 0;j < stones.size(); j++){
                if(busqueda == stones[j]){
                    int temp= map.search(busqueda);
                    map.erase(busqueda);
                    map.insert(busqueda,temp+1);
                }
            }
            if(map.search(busqueda)!=-1){
                contador += map.search(busqueda);
            }
            
        }
        return contador;
    }
};

int main(){
    Solution sol;
    cout << sol.numJewelsInStones("aA","aAAbbbbbb");

    return 0;
}