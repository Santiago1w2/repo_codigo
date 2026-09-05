#include <iostream>


int main() {
    int n = 0, k = 0;
    std::cin>>n>>k;
    int A[n];
    for (int i = 0; i < n; i++) {
        std::cin>>A[i];
        if (A[i]==0) {
        }
    }
    int lim = A[k-1];
    int contador = 0;
        for (int i = 0; i < n; i++) {
            if (A[i]>=lim && A[i]!=0) {
                contador++;
            }
        }

    std::cout << contador << std::endl;

    return 0;
}