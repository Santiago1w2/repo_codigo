#include <iostream>
#include <vector>

void hanoi(int n,int origin, int auxiliar, int destino){
    if(n == 0){
        return;
    }
    hanoi(n-1,origin,destino,auxiliar);

    std::cout << n<<" "<<origin <<" " <<destino << "\n";
    hanoi(n-1,auxiliar,origin,destino);
}
int main(){
    int n = 0;
    std::cin>>n;
    hanoi(n,1,2,3);
    return 0;
}