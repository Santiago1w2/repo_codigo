#include <iostream>
#include <vector>
void dump(std::vector<long>&A){
    for(int i = 0; i < A.size(); i++){
        std::cout << A[i];
        if(i <A.size()-1 ){
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

void clear(std::vector<long>&A){
    if(!A.empty()){
        A.clear();
    }
}

void push_back(std::vector<long>&A, int x){
    A.push_back(x);
}

int main(){
    int n = 0, q = 0;
    std::cin>>n>>q;
    std::vector<std::vector<long>> A(n);
    int a = -1;
    int b = -1;
    int c = -1;
    for(int i = 0; i < q;i++){
        std::cin>>a;
        if(a==0){
            std::cin>>b>>c;
            push_back(A[b],c);
        } else if (a==1){
            std::cin>>b;
            dump(A[b]);
        } else if(a==2){
            std::cin>>b;
            clear(A[b]);
        }
    }

    return 0;
}