#include <iostream>

int main(){
    int N = 0, M = 0;
    std::cin>>M >> N;
    int contador = 0;
    if(N%2==0 && M%2==0 ){
        contador +=((M/2)*N);
    } else  if (M%2==1 && N%2==0){
        contador+=((((M-1)/2)*N)+(N/2));
    }else if (M%2==0 && N%2==1){
        contador+=(((M)*((N-1)/2))+(M/2));
    } else {
        contador+=(((M/2)*(N-1))+(M/2)+(N/2));
    }
    std::cout << contador << std::endl;
    return 0;
}