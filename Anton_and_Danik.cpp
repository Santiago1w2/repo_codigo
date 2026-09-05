#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    std::string g = "";
    std::cin >> g;
    int A = 0;
    int D = 0;
    for (int i = 0; i < n; i++) {
        if (g[i]=='A') {
            A++;

        } else if (g[i]=='D') {
            D++;
        }
    }

    if (A>D) {
        std::cout << "Anton" << std::endl;
    } else if (A<D) {
        std::cout << "Danik" << std::endl;
    } else {
        std::cout << "Friendship" << std::endl;

    }
    return 0;
}