
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<long long> minimoNodos;
    minimoNodos.push_back(1); // Altura 0
    minimoNodos.push_back(2); // Altura 1

    while (minimoNodos.back() <= 1000000000000000000LL) {
        int tam = minimoNodos.size();

        long long siguiente = 1
            + minimoNodos[tam - 1]
            + minimoNodos[tam - 2];

        minimoNodos.push_back(siguiente);
    }

    while (t--) {
        long long n;
        cin >> n;

        // Altura minima
        long long capacidad = 1;
        int hMin = 0;

        while (capacidad < n) {
            capacidad = capacidad * 2 + 1;
            hMin++;
        }

        // Altura maxima
        int hMax = 0;

        while (hMax + 1 < (int)minimoNodos.size()
               && minimoNodos[hMax + 1] <= n) {
            hMax++;
        }

        cout << hMin << " " << hMax << '\n';
    }

    return 0;
}
