#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> reparto;

void backtracking(int restantes, int maximo){
    if(restantes==0){
        for(auto x:reparto){
            std::cout << x << " ";
        }
        std::cout << "\n";
        return;
    }
    
    int inicio = std::min(restantes,maximo);
    for(int i = inicio; i >=1;i--){
        reparto.push_back(i); // elegir
        backtracking(restantes-i,i); //explorar
        reparto.pop_back(); // retroceder
    }
}
int main(){
    int n = 0;
    std::cin>>n;
    backtracking(n,n);
    return 0;
}