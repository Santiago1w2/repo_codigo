#include <iostream>

int main(){
    std::string a = "", b = "";
    std::cin>>a;
    std::cin>>b;
    int contadorA = 0;
    int contadorB = 0;
    for(int i = 0; i<a.size();i++){
        char A = a[i];
        char B = b[i];
        if(A<97){
            A+=32;
        } else if(B<97) {
            B+=32;
        }
        
        contadorA+=(A-0);
        contadorB+=(B-0);
    }
    if(contadorA<contadorB){
        std::cout << -1 << std::endl;
    } else if(contadorA>contadorB){
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}