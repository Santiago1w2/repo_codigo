#include <iostream>
#include <vector>
int n, X;
std::vector<int> monedas;
int backtracking(int i , int suma){
    if(i == n){
        if(suma == X){
            return 1;
        }
        return 0;
    }

    int no_contar = backtracking(i+1,suma);
    int contar = backtracking(i+1,suma+monedas[i]);
    return no_contar+contar;
}
int main(){
    std::cin>>n>>X;
    monedas.resize(n);
    for(int i = 0; i < n; i++){
        std::cin>>monedas[i];
    }

    std::cout<< backtracking(0,0);
    return 0;

}