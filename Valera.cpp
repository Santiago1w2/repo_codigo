
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n = 4;
    std::vector<int>erraduras(n);
    for (int i = 0; i < n; i++) {
        std::cin>>erraduras[i];
    }
    std::sort(erraduras.begin(), erraduras.end());
    int contador = 0;
    for (int i = 0; i < n-1; i++) {
        if (erraduras[i]==erraduras[i+1]) {
            contador++;
        }
    }
    std::cout << contador << std::endl;

    return 0;
}