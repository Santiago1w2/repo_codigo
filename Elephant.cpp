#include <iostream>

int main() {
    int x;
    std::cin >> x;

    int contador = x / 5 + (x % 5 != 0);

    std::cout << contador << std::endl;

    return 0;
}