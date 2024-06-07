#include <iostream>
#include <stdexcept>
using namespace std;

// - 1.队列的声明
template<typename T>
class Queue{
private:
    T* data;
    int front;
    int rear;
    int capacity;
    void resize();
public:
    Queue():front(0),rear(0),capacity(10),data(new T[10]){}
    ~Queue(){};
    void enqueue(T value){};
    T dequeue(){};
    T getFront() const{};
    int getSize() const{};
};

// - 2.队列函数实现
// - 2-1.扩容函数
template<typename T>
void Queue<T>::resize(){
    T* new_queue = new T [capacity*2];
    for(int i=0;i<capacity;++i){
        new_queue[i] = data[i];
    }
    delete[] data;
    data = new_queue;
    capacity*=2;
}
// - 2-2.入队函数
template<typename T>
void Queue<T>::enqueue(T value){
    if(rear == capacity){
        resize();
    }
    data[rear++] = value;
}
// - 2-3.出队函数
template<typename T>
T Queue<T>::dequeue(){
    if(front == rear){
        throw underflow_error("Queue is empty!");
    }
    return data[front++];
}
// - 2-4.获得队列首位元素
template<typename T>
T Queue<T>::getFront() const{
    if(rear == front){
        throw underflow_error("Queue is empty!");
    }
    return data[front];
}
// - 2-5.获得当前队列长度
template<typename T>
int Queue<T>::getSize() const{
    return rear-front;
}
// - 3.队列的销毁
template<typename T>
Queue<T>::~Queue(){
    delete[] data;
}

// - test zone
int main(){
    
}