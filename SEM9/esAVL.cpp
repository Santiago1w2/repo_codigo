#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

std::vector<int> nodos;
std::vector<int> izq;
std::vector<int> der;
std::vector<int> orden;
int altura (int i){
    if(i == 0){
        return 0;
    }
    int hi = altura(izq[i]);
    int hd = altura(der[i]);
    return 1 + std::max(hi,hd);
}
bool esBalanceado(int i ){
    if(i == 0){
        return true;
    }
    int hi = altura(izq[i]);
    int hd = altura(der[i]);
    if(std::abs(hi-hd)>1){
        return false;
    }
    return esBalanceado(izq[i]) && esBalanceado(der[i]);
}


void inorder(int i, int n) {
    if (i == 0) {
        return;
    }

    inorder(izq[i], n);
    orden.push_back(nodos[i]);
    inorder(der[i], n);
}

bool esBST(int i, int n) {
    orden.clear();
    inorder(i, n);

    for (int j = 1; j < (int)orden.size(); j++) {
        if (orden[j - 1] > orden[j]) {
            return false;
        }
    }

    return true;
}


int main() {
    int t, n;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> n;
        nodos.assign(n + 1, 0);
        izq.assign(n + 1, 0);
        der.assign(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            int k, l, r;
            std::cin >> k >> l >> r;
            nodos[j] = k;
            izq[j] = l;
            der[j] = r;
        }
        if(esBST(1,n)){
            if(esBalanceado(1)){
                std::cout << "AVL\n";
            } else {
                std::cout << "BST\n";
            }
        } else {
            std::cout << "NINGUNO\n";
        }
    }
    return 0;
}