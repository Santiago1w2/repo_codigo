#include <iostream>
#include <vector>
int n = 3;
std::vector<std::string> contras;

void bracktracking(int i){
    if(i==n){
        for(auto x:contras){
            std::cout << x << " ";
        }
        std::cout << "\n";
        return;
    }

    contras.push_back("a"); //hacer
    bracktracking(i+1); //explorar
    contras.pop_back(); //deshacer

    contras.push_back("b");
    bracktracking(i+1);
    contras.pop_back();


}

int main(){
    bracktracking(0);
    return 0;
}