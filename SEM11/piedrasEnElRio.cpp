#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> a;

int bfs(int inicio) {
    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[inicio] = 0;
    q.push(inicio);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int derecha = u + a[u];
        int izquierda = u - a[u];

        if (derecha <= n && dist[derecha] == -1) {
            dist[derecha] = dist[u] + 1;
            q.push(derecha);
        }

        if (izquierda >= 1 && dist[izquierda] == -1) {
            dist[izquierda] = dist[u] + 1;
            q.push(izquierda);
        }
    }

    return dist[n];
}

int main() {
    cin >> n;

    a.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << bfs(1);

    return 0;
}