
#include <iostream>
#include <vector>
#include <string>

std::vector<char> cadena;
std::vector<std::string> resultados;
int contador = 0;
int n;

bool validar() {
    for (int i = 1; i < cadena.size(); i++) {
        if (cadena[i] == '1' && cadena[i - 1] == '1') {
            return false;
        }
    }
    return true;
}

void backtracking(int a) {
    if (a == n) {
        if (validar()) {
            contador++;
            std::string prob = "";
            for (int i = 0; i < n; i++) {
                prob.push_back(cadena[i]);
            }
            resultados.push_back(prob);
        }
        return;
    }
    cadena.push_back('0');
    backtracking(a + 1);
    cadena.pop_back();
    cadena.push_back('1');
    backtracking(a + 1);
    cadena.pop_back();
}

int main() {
    std::cin >> n;

    backtracking(0);

    std::cout << contador << "\n";

    for (auto x : resultados) {
        std::cout << x << "\n";
    }

    return 0;
}
