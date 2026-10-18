#include <iostream>
#include <vector>

std::vector<bool> d1;
std::vector<bool>d2;
std::vector<bool>col;
std::vector<int>pos;
std::vector<std::string> tablero;
int n;
long long formas;
void reinas(int f){
    if(f==n){
        formas++;
        return;
    }
    for (int c = 0; c < n;c++){
        if( tablero[f][c] == '.' && !col[c] && !d1[f - c +n-1] && !d2[f+c]){
            col[c]=true;
            d1[f - c +n-1]=true;
            d2[f+c]=true;
            pos[f]=c;
            reinas(f + 1);
            col[c]=false;
            d1[f - c +n-1]=false;
            d2[f+c]=false;
        }
    }
}

int main() {
    std::cin >> n;

    tablero.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> tablero[i];
    }

    d1.assign(2 * n - 1, false);
    d2.assign(2 * n - 1, false);
    col.assign(n, false);
    pos.resize(n);

    reinas(0);

    std::cout << formas << '\n';

    return 0;
}