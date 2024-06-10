#include<iostream>
#include<stdexcept>

using namespace std;

// - 1.定义栈,作为底层容器
template<typename T>
class stack{
private:
    T* elements;
    int size;
    int capacity;
    void resize();
public:
    stack():elements(new T[10]),size(0),capacity(10){}
    ~stack();
    void push(T data);
    T pop();
    T top() const;
    int getSize() const;
    bool empty() const;

    // - test function: print
    void print(){
        for(int i=0;i<size;++i){
            cout<<elements[i]<<endl;
        }
    }
};

// - resize
template<typename T>
void stack<T>::resize(){
    T* new_elements = new T[capacity*2];
    for(int i=0;i<capacity;++i){
        new_elements[i] = elements[i];
    }
    delete[] elements;
    elements = new_elements;
    capacity*=2;
}

// - destory
template<typename T>
stack<T>::~stack(){
    delete[] elements;
}

// - push data ito stack
template<typename T>
void stack<T>::push(T data){
    if(size == capacity){
        resize();
    }
    elements[size++] = data;
}

// - put data out of stack
template<typename T>
T stack<T>::pop(){
    return elements[--size];
}

// - obtain the top element of stack
template<typename T>
T stack<T>::top() const{
    return elements[size-1];
}

// - obtain the size of stack
template<typename T>
int stack<T>::getSize() const{
    return size;
}

// - check if the stack is empty
template<typename T>
bool stack<T>::empty() const{
    if(size) return false;
    else return true;
}

// - 2. 利用栈构建队列
template<typename T>
class myQueue{
private:
    stack<T> s1;
    stack<T> s2;
public:
    myQueue(){}
    void enqueue(T data);
    T dequeue();
    T getFront();
    int getSize() const;

    // - test function
    void print(){
        s1.print();
    }
};

// - enqueue
template<typename T>
void myQueue<T>::enqueue(T data){
    s1.push(data);
}

// - dequeue
template<typename T>
T myQueue<T>::dequeue(){
    if(s1.empty()){
        throw underflow_error("Queue is empty!");
    }
    while(s1.getSize()>1){
        s2.push(s1.pop());
    }
    T result = s1.pop();
    while(s2.getSize()>0){
        s1.push(s2.pop());
    }
    return result;
}

// - getFront
template<typename T>
T myQueue<T>::getFront() {
    if(s1.empty()){
        throw underflow_error("Queue is empty!");
    }
    while(s1.getSize()>1){
        s2.push(s1.pop());
    }
    T result = s1.top();
    while(s2.getSize()>0){
        s1.push(s2.pop());
    }
    return result;
}

// - get size of queue
template<typename T>
int myQueue<T>::getSize() const{
    return s1.getSize();
}

// - test zone
int main(){
    myQueue<int> q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.dequeue();
    q1.print();
}