#include <bits/stdc++.h>
using namespace std;

bool distintos(int x) {
    vector<bool> used(10, false);

    while (x > 0) {
        int digito = x % 10;

        if (used[digito]) {
            return false;
        }

        used[digito] = true;

        x /= 10;
    }

    return true;
}

int main() {
    int l, r;
    cin >> l >> r;

    for (int x = l; x <= r; x++) {
        if (distintos(x)) {
            cout << x << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}