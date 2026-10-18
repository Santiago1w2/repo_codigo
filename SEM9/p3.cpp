
#include <iostream>
#include <vector>
#include <array>
#include <numeric>
using namespace std;

struct Node {
    int val;
    Node* izq;
    Node* der;
    Node* padre;

    Node(int v) : val(v), izq(nullptr), der(nullptr), padre(nullptr) {}
};

int n;
vector<int> a;
vector<vector<char>> compatible;
vector<vector<array<signed char, 2>>> dp;
vector<vector<array<int, 2>>> elegido;
bool puede(int l, int r, int lado) {
    if (l > r) {
        return true;
    }

    signed char& res = dp[l][r][lado];

    if (res != -1) {
        return res;
    }

    int padre = (lado == 0 ? l - 1 : r + 1);

    for (int i = l; i <= r; i++) {
        if (padre != 0 && padre != n + 1 &&
            !compatible[padre][i]) {
            continue;
        }
        if (!puede(l, i - 1, 1)) {
            continue;
        }

        if (!puede(i + 1, r, 0)) {
            continue;
        }

        elegido[l][r][lado] = i;
        res = 1;
        return true;
    }

    res = 0;
    return false;
}

Node* construir(int l, int r, int lado, Node* padre) {
    if (l > r) {
        return nullptr;
    }

    int i = elegido[l][r][lado];

    Node* nodo = new Node(a[i]);
    nodo->padre = padre;

    nodo->izq = construir(l, i - 1, 1, nodo);
    nodo->der = construir(i + 1, r, 0, nodo);

    return nodo;
}

void liberar(Node* nodo) {
    if (nodo == nullptr) {
        return;
    }

    liberar(nodo->izq);
    liberar(nodo->der);
    delete nodo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    a.resize(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    compatible.assign(n + 2, vector<char>(n + 2, false));

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (gcd(a[i], a[j]) > 1) {
                compatible[i][j] = true;
                compatible[j][i] = true;
            }
        }
    }

    dp.resize(n + 2);
    elegido.resize(n + 2);

    for (int i = 0; i < n + 2; i++) {
        dp[i].resize(n + 2);
        elegido[i].resize(n + 2);

        for (int j = 0; j < n + 2; j++) {
            dp[i][j] = {-1, -1};
            elegido[i][j] = {-1, -1};
        }
    }

    if (!puede(1, n, 0)) {
        cout << "No\n";
        return 0;
    }

    Node* root = construir(1, n, 0, nullptr);

    cout << "Yes\n";

    liberar(root);

    return 0;
}
