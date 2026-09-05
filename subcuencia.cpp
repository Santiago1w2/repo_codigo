#include <iostream>
#include <stack>
int main(){
    std::string S = "";
    std::stack<char> palabra;
    palabra.push('o');
    palabra.push('l');
    palabra.push('l');
    palabra.push('e');
    palabra.push('h');

    std::cin>>S;
    for(int i = 0; i < S.size(); i++){
        if(palabra.empty()){
            break;
        }

        if(S[i]==palabra.top()){
            palabra.pop();
        } 
    }

    if(palabra.empty()){
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}