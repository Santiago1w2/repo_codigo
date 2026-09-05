#include <iostream>
#include <vector>

int main(){
    std::vector<int> e(4);
    for(int i = 0; i < 4;i++){
        std::cin>>e[i];
    }

    int diferentes = 0;
    for(int i = 0; i < 4;i++){
        bool repetidos = false;
        for(int j = 0; j<i;j++){
            if(e[i]==e[j]){
                repetidos = true;
                break;
            }
            
        }
        if(!repetidos){
            diferentes++;
        }
    }

    std::cout << 4-diferentes << std::endl;
    return 0;
}