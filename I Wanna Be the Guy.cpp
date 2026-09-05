#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> levels(n + 1, false);

    int p;
    cin >> p;

    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;

        levels[x] = true;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;

        levels[y] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!levels[i]) {
            cout << "Oh, my keyboard!\n";
            return 0;
        }
    }

    cout << "I become the guy.\n";

    return 0;
}