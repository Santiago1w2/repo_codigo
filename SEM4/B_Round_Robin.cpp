#include <iostream>
#include <vector>
struct Process{

    std::string name;
    int time;

    Process(std::string n = "", int t = 0): name(n), time(t){}

};
template<typename T>

struct Queue{

    std::vector<T> buffer;

    int front;
    int cnt;

    Queue(int capacity = 1): buffer(capacity), front(0), cnt(0){}

    bool empty(){

        return cnt == 0;
    }

    void crecer(){

        std::vector<T> new_buffer(buffer.size() * 2);

        for(int i = 0; i < cnt; i++){

            new_buffer[i] = buffer[(front + i) % buffer.size()];
        }

        buffer = new_buffer;

        front = 0;
    }

    void enqueue(T data){

        if(cnt == buffer.size()){

            crecer();
        }

        int pos = (front + cnt) % buffer.size();

        buffer[pos] = data;

        cnt++;
    }

    void dequeue(){

        if(empty()){

            return;
        }

        front = (front + 1) % buffer.size();

        cnt--;
    }

    T& get_front(){

        return buffer[front];
    }

};

int main(){

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int q;

    std::cin >> n >> q;

    Queue<Process> cola;

    for(int i = 0; i < n; i++){

        std::string name;
        int time;

        std::cin >> name >> time;

        cola.enqueue(Process(name, time));
    }

    int tiempo_total = 0;

    while(!cola.empty()){

        Process actual = cola.get_front();

        cola.dequeue();

        if(actual.time <= q){

            tiempo_total += actual.time;

            std::cout << actual.name << " " << tiempo_total << '\n';

        }
        else{

            tiempo_total += q;

            actual.time -= q;

            cola.enqueue(actual);
        }
    }

    return 0;
}