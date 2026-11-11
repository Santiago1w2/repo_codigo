#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(int x, int b){
    queue<int> cola;
    int contador = 0;
    cola.push(x);
    while(!cola.empty()){
        int sx = cola.front();
        cola.pop();
        if(sx == b){
            return contador;
        }
        if(sx-1>=2){
            cola.push(sx-1);
            contador++;
        
        if(2*sx <= b){
            cola.push(2*sx);
            contador++;
        }        
    }
    return -1;}
}
int DFS(int x, int b){
    return 0;
}


int main(){
    int x, b;
    cin>>x>>b;
    cout << BFS(x,b);
    return 0;
}