#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    Node *next;
    int key;
    long long value;
    Node()
    {
    }
    Node(int _key, long long _value)
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
        n = 0;

        A = new Node *[m];

        for (int i = 0; i < m; i++)
            A[i] = nullptr;
    }

    int hash(int k)
    {
        return (k % m + m) % m;
    }

    void add(int k, long long v)
    {
        int p = hash(k);

        Node *temp = A[p];

        while (temp != nullptr)
        {
            if (temp->key == k)
            {
                temp->value += v;
                return;
            }

            temp = temp->next;
        }

        Node *new_node = new Node(k, v);

        new_node->next = A[p];
        A[p] = new_node;

        n++;
    }

    long long search(int k)
    {
        int p = hash(k);

        Node *temp = A[p];

        while (temp != nullptr)
        {
            if (temp->key == k)
                return temp->value;

            temp = temp->next;
        }

        return -1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        HashTable map(200003);

        int k = n / 2;

        // Distancia 0
        map.add(0, 1);

        // Distancias 1, 2, ..., k
        for (int d = 1; d <= k; d++)
        {
            map.add(d, 8LL * d);
        }

        long long answer = 0;

        for (int d = 1; d <= k; d++)
        {
            long long cantidad = map.search(d);

            answer += cantidad * d;
        }

        cout << answer << '\n';
    }

    return 0;
}