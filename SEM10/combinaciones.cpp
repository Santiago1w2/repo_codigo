#include <iostream>
#include <vector>
std::vector<int>com;

int n = 4;
int k = 2;

void backtracking(int n, int k, int desde){
    if(com.size()==k){
        for(auto x:com){
            std::cout << x <<" ";
        }
        std::cout << "\n";
        return;
    }

    for(int i = desde; i <= n; i++){
        com.push_back(i);
        backtracking(n,k,i+1);
        com.pop_back();
    }
}


int main(){
    backtracking(4,2,1);
    return 0;
}