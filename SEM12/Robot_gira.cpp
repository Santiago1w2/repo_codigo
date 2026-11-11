
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <iostream>
using namespace std;

int n, m;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int BFS(vector<string>& laberinto) {

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(4, -1)));

    queue<tuple<int, int, int>> cola;

    dist[0][0][1] = 0;
    cola.push({0, 0, 1});

    while (!cola.empty()) {

        auto [r, c, d] = cola.front();
        cola.pop();

        int actual = dist[r][c][d];

        if (r == n - 1 && c == m - 1) {
            return actual;
        }

        int izq = (d + 3) % 4;

        if (dist[r][c][izq] == -1) {
            dist[r][c][izq] = actual + 1;
            cola.push({r, c, izq});
        }

        int der = (d + 1) % 4;

        if (dist[r][c][der] == -1) {
            dist[r][c][der] = actual + 1;
            cola.push({r, c, der});
        }

        int nr = r + dr[d];
        int nc = c + dc[d];

        if (nr >= 0 && nr < n &&
            nc >= 0 && nc < m &&
            laberinto[nr][nc] == '.') {

            if (dist[nr][nc][d] == -1) {
                dist[nr][nc][d] = actual + 1;
                cola.push({nr, nc, d});
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;

    vector<string> laberinto(n);

    for (int i = 0; i < n; i++) {
        cin >> laberinto[i];
    }

    cout << BFS(laberinto) << "\n";

    return 0;
}
