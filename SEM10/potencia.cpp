#include <iostream>

int potencia(int a,int n){
    if(n==0){
        return 1;
    }
    int h = potencia(a,n/2);
    if(n%2==0){
        return h * h;
    }
    return h*h*a;
}

int main(){
    std::cout << potencia(2,11);
    return 0;
}