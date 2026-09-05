#include <iostream>
#include <vector>


int main(){
    int N = 0;
    std::cin>>N;
    std::vector<long> A(N);
    int contador = 0;
    for(int i = 0; i < N; i++){
        std::cin>>A[i];
    }
    bool seguir = true;
    while (seguir){
        int cont = 0;
        for(int i = 0; i < N; i++){
            if(A[i]%2==0){
                A[i]=A[i]/2;
                cont++;
            } else {
                cont--;
            }            
        }
        if(cont == N){
            contador++;
        } else {
            seguir = false;
        }
    }
    std::cout << contador << std::endl;

    return 0;
}