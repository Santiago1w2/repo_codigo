#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

template<typename T>
struct Pila{
    std::vector<T> datos;
   
    void push(T x){
        datos.push_back(x);
    
    }
    void pop(){
        if(!datos.empty()){
            datos.pop_back();
        
        }
    
    }
    T top(){
        T x = datos.back();
        return x;
    }

    bool empty(){
        return datos.empty;
    }

    int size(){
        return datos.size();
    }
};


template<typename T> 
struct ColaIngenua{
    std::vector<T> datos;

    void enqueue(T x){datos.push_back(x);}
    void dequeue() {datos.erase(datos.begin());}
    T front() const {return datos.front();}
};


template<typename T>
struct Queue{
    std::vector<T> buffer;
    int frente = 0;
    int cnt = 0;

    ColaCircular(int cap = 1): buffer(cap){}    
    bool empty() const {return cnt == 0;}
    int size() const {return ctn;}
    void crecer(){

    }
    void enqueue(T x){
        if(cnt==(int)buf.size()){
            crecer();
        }

        int pos = (frente+cnt)%buffer.size();
        buf[pos] = x;
        cnt++;
    }
};

template<typename T>
struct DqueueCircle{
    std::vector<T> buffer;
    int frente = 0;
    int cnt = 0;
    DqueueCircle(int cap = 1):buffer(cap){}

    

};
int main(){
    Pila<int> pila;

    pila.push(3);
    pila.push(4);
    std::cout << pila.datos[1] << std::endl;


    return 0;
}
