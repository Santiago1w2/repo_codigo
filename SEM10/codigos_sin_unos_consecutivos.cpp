#include <iostream>
#include <vector>

std::vector<int> cadena;
int n = 3;
bool validar() {
    for (int i = 1; i < cadena.size(); i++) {
        if (cadena[i] == 1 && cadena[i - 1] == 1) {
            return false;
        }
    }
    return true;
}
void backtraking(int i){
    if(i == n){
        if(validar()){
            for(int i = 0; i < n; i++){
                if(i != 0){
                    std::cout << " ";
                }
                std::cout << cadena[i];
            }
            std::cout << "\n";
        }
        
        return;
    }
    cadena.push_back(0);
    backtraking(i+1);
    cadena.pop_back();

    cadena.push_back(1);
    backtraking(i+1);
    cadena.pop_back();
}
int main(){
    backtraking(0);
    return 0;
}