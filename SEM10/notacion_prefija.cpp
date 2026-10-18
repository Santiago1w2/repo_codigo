#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> numeros;
int pos = 0;

long long resolver() {
    std::string valor = numeros[pos++];

    if (valor != "+" && valor != "-" && valor != "*") {
        return std::stoll(valor);
    }

    long long a = resolver();
    long long b = resolver();

    if (valor == "+") return a + b;
    if (valor == "-") return a - b;
    return a * b;
}

int main() {
    int m;
    std::cin >> m;

    numeros.resize(m);

    for (int i = 0; i < m; i++) {
        std::cin >> numeros[i];
    }

    std::cout << resolver() << '\n';
    return 0;
}