#include <iostream>
#include <algorithm>

int main() {
    std::string n = "";
    std::cin >> n;
    std::sort(n.begin(), n.end());
    int contador = 0;
    for (int i = 0; i < n.size(); i++) {
        if (n[i] == n[i + 1]) {
            contador++;
        }
    }
    if ((n.size()-contador)%2 == 0) {
        std::cout << "CHAT WITH HER!" << std::endl;
    } else {
        std::cout << "IGNORE HIM!" << std::endl;
    }

    return 0;
}