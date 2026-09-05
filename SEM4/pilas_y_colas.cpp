#include <iostream>
#include <vector>

// =====================================================
// 1. STACK
// LIFO: Last In First Out
// =====================================================

template<typename T>
struct Stack{

    std::vector<T> buffer;

    void push(T data){

        buffer.push_back(data);
    }

    void pop(){

        if(empty()){
            return;
        }

        buffer.pop_back();
    }

    T& top(){

        return buffer.back();
    }

    bool empty(){

        return buffer.empty();
    }

    int size(){

        return buffer.size();
    }

    void clear(){

        buffer.clear();
    }

    void print(){

        for(int i = buffer.size() - 1; i >= 0; i--){

            std::cout << buffer[i] << " ";
        }

        std::cout << '\n';
    }
};



// =====================================================
// 2. QUEUE
// FIFO: First In First Out
// =====================================================

template<typename T>
struct Queue{

    std::vector<T> buffer;

    int front_index;

    Queue(): front_index(0){}

    void enqueue(T data){

        buffer.push_back(data);
    }

    void dequeue(){

        if(empty()){
            return;
        }

        front_index++;
    }

    T& front(){

        return buffer[front_index];
    }

    T& back(){

        return buffer.back();
    }

    bool empty(){

        return front_index == buffer.size();
    }

    int size(){

        return buffer.size() - front_index;
    }

    void clear(){

        buffer.clear();

        front_index = 0;
    }

    void print(){

        for(int i = front_index; i < buffer.size(); i++){

            std::cout << buffer[i] << " ";
        }

        std::cout << '\n';
    }
};



// =====================================================
// 3. DEQUE
// Double Ended Queue
//
// Puede insertar/eliminar por ambos extremos.
// =====================================================

template<typename T>
struct Deque{

    std::vector<T> buffer;

    int front_index;
    int cnt;

    Deque(int capacity = 1)
        : buffer(capacity),
          front_index(0),
          cnt(0){}


    bool empty(){

        return cnt == 0;
    }


    int size(){

        return cnt;
    }


    void crecer(){

        int nueva_capacidad = buffer.size() * 2;

        if(nueva_capacidad == 0){
            nueva_capacidad = 1;
        }

        std::vector<T> nuevo(nueva_capacidad);

        for(int i = 0; i < cnt; i++){

            nuevo[i] =
                buffer[(front_index + i) % buffer.size()];
        }

        buffer = nuevo;

        front_index = 0;
    }


    void push_back(T data){

        if(cnt == buffer.size()){

            crecer();
        }

        int pos =
            (front_index + cnt) % buffer.size();

        buffer[pos] = data;

        cnt++;
    }


    void push_front(T data){

        if(cnt == buffer.size()){

            crecer();
        }

        front_index =
            (front_index - 1 + buffer.size())
            % buffer.size();

        buffer[front_index] = data;

        cnt++;
    }


    void pop_front(){

        if(empty()){

            return;
        }

        front_index =
            (front_index + 1) % buffer.size();

        cnt--;
    }


    void pop_back(){

        if(empty()){

            return;
        }

        cnt--;
    }


    T& front(){

        return buffer[front_index];
    }


    T& back(){

        int pos =
            (front_index + cnt - 1)
            % buffer.size();

        return buffer[pos];
    }


    void clear(){

        front_index = 0;

        cnt = 0;
    }


    void print(){

        for(int i = 0; i < cnt; i++){

            int pos =
                (front_index + i)
                % buffer.size();

            std::cout << buffer[pos] << " ";
        }

        std::cout << '\n';
    }
};



// =====================================================
// 4. CIRCULAR QUEUE
//
// Queue implementada usando un vector circular.
// =====================================================

template<typename T>
struct CircularQueue{

    std::vector<T> buffer;

    int front_index;
    int cnt;


    CircularQueue(int capacity = 1)
        : buffer(capacity),
          front_index(0),
          cnt(0){}


    bool empty(){

        return cnt == 0;
    }


    int size(){

        return cnt;
    }


    int capacity(){

        return buffer.size();
    }


    void crecer(){

        int nueva_capacidad =
            buffer.size() * 2;

        if(nueva_capacidad == 0){

            nueva_capacidad = 1;
        }

        std::vector<T> new_buffer(
            nueva_capacidad
        );


        for(int i = 0; i < cnt; i++){

            new_buffer[i] =
                buffer[
                    (front_index + i)
                    % buffer.size()
                ];
        }


        buffer = new_buffer;

        front_index = 0;
    }


    void enqueue(T data){

        if(cnt == buffer.size()){

            crecer();
        }

        int pos =
            (front_index + cnt)
            % buffer.size();

        buffer[pos] = data;

        cnt++;
    }


    void dequeue(){

        if(empty()){

            return;
        }

        front_index =
            (front_index + 1)
            % buffer.size();

        cnt--;
    }


    T& front(){

        return buffer[front_index];
    }


    T& back(){

        int pos =
            (front_index + cnt - 1)
            % buffer.size();

        return buffer[pos];
    }


    void clear(){

        front_index = 0;

        cnt = 0;
    }


    void print(){

        for(int i = 0; i < cnt; i++){

            int pos =
                (front_index + i)
                % buffer.size();

            std::cout
                << buffer[pos]
                << " ";
        }

        std::cout << '\n';
    }
};



// =====================================================
// MAIN DE EJEMPLO
// =====================================================

int main(){

    // -------------------------
    // STACK
    // -------------------------

    Stack<int> pila;

    pila.push(10);
    pila.push(20);
    pila.push(30);

    std::cout << "Stack:\n";

    pila.print();

    std::cout
        << "top: "
        << pila.top()
        << '\n';

    pila.pop();

    pila.print();



    // -------------------------
    // QUEUE
    // -------------------------

    Queue<int> cola;

    cola.enqueue(10);
    cola.enqueue(20);
    cola.enqueue(30);

    std::cout << "\nQueue:\n";

    cola.print();

    std::cout
        << "front: "
        << cola.front()
        << '\n';

    std::cout
        << "back: "
        << cola.back()
        << '\n';

    cola.dequeue();

    cola.print();



    // -------------------------
    // DEQUE
    // -------------------------

    Deque<int> deque;

    deque.push_back(20);
    deque.push_back(30);

    deque.push_front(10);

    deque.push_front(5);

    std::cout << "\nDeque:\n";

    deque.print();

    std::cout
        << "front: "
        << deque.front()
        << '\n';

    std::cout
        << "back: "
        << deque.back()
        << '\n';

    deque.pop_front();

    deque.pop_back();

    deque.print();



    // -------------------------
    // CIRCULAR QUEUE
    // -------------------------

    CircularQueue<int> circular;

    circular.enqueue(10);
    circular.enqueue(20);
    circular.enqueue(30);
    circular.enqueue(40);

    std::cout << "\nCircular Queue:\n";

    circular.print();

    circular.dequeue();
    circular.dequeue();

    circular.enqueue(50);
    circular.enqueue(60);

    circular.print();

    return 0;
}