
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <iostream>
using namespace std;

int n, m;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int BFS(vector<string>& matriz) {
    deque<pair<int,int>> cola;

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    dist[0][0] = 0;
    cola.push_front({0, 0});

    while (!cola.empty()) {
        auto [x, y] = cola.front();
        cola.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            int costo = (matriz[nx][ny] == '#') ? 1 : 0;

            if (dist[x][y] + costo < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + costo;

                if (costo == 0)
                    cola.push_front({nx, ny});
                else
                    cola.push_back({nx, ny});
            }
        }
    }

    return dist[n-1][m-1];
}

int main() {
    cin >> n >> m;

    vector<string> matriz(n);

    for (int i = 0; i < n; i++)
        cin >> matriz[i];

    cout << BFS(matriz) << "\n";

    return 0;
}