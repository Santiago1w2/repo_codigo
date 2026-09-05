#include <iostream>
#include <stack>


int main(){
    int N = 0;
    std::cin>>N;

    std::string S = "";
    std::cin>>S;

    std::stack<char> T;
    T.push(S[0]);
    for(int i = 1; i < N; i++){
        if(S[i] != T.top()){
            T.push(S[i]);
        }
    }
    std::cout << T.size() << std::endl;
    return 0;
}