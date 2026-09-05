#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        int minimo = INT_MAX;
        int maximo = INT_MIN;

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            minimo = min(minimo, a[i]);
            maximo = max(maximo, a[i]);
        }

        cout << maximo - minimo << '\n';
    }

    return 0;
}
