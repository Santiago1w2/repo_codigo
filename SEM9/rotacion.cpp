#include <iostream>
#include <vector>

std::vector<int>nodos;
std::vector<int>izq;
std::vector<int>der;
std::vector<int>padre;
int raiz;
void inorder(int i){
    if(i == 0){
        return;
    }
    inorder(izq[i]);
    std::cout << nodos[i] << " ";
    inorder(der[i]);
}
void conectarPadre(int p, int viejo, int nuevo){
    if(p == 0){
        raiz = nuevo;
    } else if(izq[p]==viejo){
        izq[p]=nuevo;
    } else {
        der[p]=nuevo;
    }
    if(nuevo!=0){
        padre[nuevo]=p;
    }
}
void rotarIzqierda(int x){
    int y = der[x];
    int p = padre[x];
    int b = izq[y];
    conectarPadre(p,x,y);
    der[x]=b;
    if(b!=0){
        padre[b]=x;
    }
    izq[y]=x;
    padre[x]=y;
}
void rotarDerecha(int y){
    int x = izq[y];
    int p = padre[y];
    int b = der[x];
    conectarPadre(p,y,x);
    izq[y]=b;
    if(b!=0){
        padre[b]=y;
    }
    der[x]=y;
    padre[y]=x;
}
void imprimir(int n){
    for(int i = 1; i <= n; i++ ){
        std::cout << izq[i] << " " << der[i] << "\n";
    }
}
int main(){
    int n = 0, q = 0;

    std::cin>>n>>q;
    nodos.assign(n+1,0);
    izq.assign(n+1,0);
    der.assign(n+1,0);
    padre.assign(n+1,0);

    for(int i = 1; i <= n; i++){
        int l = 0, r = 0;
        std::cin>>l>>r;
        nodos[i]=i;
        izq[i]=l;
        der[i]=r;
        if(l!=0){
            padre[l]=i;
        }
        if(r!=0){
            padre[r]=i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (padre[i] == 0) {
            raiz = i;
            break;
        }
    }
    for(int i = 1; i <=q;i++){
        char letra;
        int x;
        std::cin>>letra>>x;
        if(letra=='D'){
            rotarDerecha(x);
        } else if(letra=='I'){
            rotarIzqierda(x);
        }
    }
    std::cout << raiz<<"\n";
    imprimir(n);
    return 0;
}