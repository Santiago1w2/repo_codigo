#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
    Node* izq;
    Node* der;
    Node* father;
    long long data;

    Node(long long d)
        : der(nullptr), izq(nullptr), father(nullptr), data(d) {}
};

class binary_tree
{
    Node* root;

    Node* buscar(Node* root, long long a)
    {
        if (root == nullptr || a == root->data)
        {
            return root;
        }

        if (a < root->data)
        {
            return buscar(root->izq, a);
        }

        return buscar(root->der, a);
    }

    Node* maximo(Node* root)
    {
        if (root == nullptr)
            return nullptr;

        while (root->der != nullptr)
        {
            root = root->der;
        }

        return root;
    }

    void insertar(Node*& root, long long k)
    {
        Node* y = nullptr;
        Node* x = root;

        while (x != nullptr)
        {
            y = x;

            if (k < x->data)
            {
                x = x->izq;
            }
            else
            {
                x = x->der;
            }
        }

        Node* z = new Node(k);

        z->father = y;

        if (y == nullptr)
        {
            root = z;
        }
        else if (k < y->data)
        {
            y->izq = z;
        }
        else
        {
            y->der = z;
        }
    }

    /*
        Comprueba si podemos tener x turnos
        de tipo "just play".
    */
    bool sePuede(long long x,
                 long long k,
                 long long n,
                 long long a,
                 long long b)
    {
        long long consumo =
            x * a + (n - x) * b;

        return consumo < k;
    }

    /*
        Esta función utiliza la misma idea
        de búsqueda de un BST.

        izquierda = valores menores
        derecha   = valores mayores
    */
    long long buscarRespuesta(long long k,
                              long long n,
                              long long a,
                              long long b)
    {
        long long izquierda = 0;
        long long derecha = n;

        long long respuesta = -1;

        while (izquierda <= derecha)
        {
            long long medio =
                izquierda + (derecha - izquierda) / 2;

            if (sePuede(medio, k, n, a, b))
            {
                /*
                    medio funciona.

                    Entonces buscamos uno
                    todavía mayor.

                    En un BST:
                    derecha.
                */
                respuesta = medio;
                izquierda = medio + 1;
            }
            else
            {
                /*
                    medio NO funciona.

                    Entonces buscamos uno
                    menor.

                    En un BST:
                    izquierda.
                */
                derecha = medio - 1;
            }
        }

        return respuesta;
    }

public:

    binary_tree()
    {
        root = nullptr;
    }

    void insertar_aux(long long k)
    {
        insertar(root, k);
    }

    bool buscar_aux(long long k)
    {
        return buscar(root, k) != nullptr;
    }

    /*
        NUEVO MÉTODO PARA EL PROBLEMA
    */
    long long resolver(long long k,
                       long long n,
                       long long a,
                       long long b)
    {
        return buscarRespuesta(k, n, a, b);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    binary_tree arbol;

    while (q--)
    {
        long long k, n, a, b;

        cin >> k >> n >> a >> b;

        cout << arbol.resolver(k, n, a, b) << '\n';
    }

    return 0;
}