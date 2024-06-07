#include<iostream>
#include<stdexcept>

using namespace std;

// - 1.定义一个队列,实现相关函数
template<typename T>
class Queue{
private:
    T* elements;
    int front;
    int rear;
    int capacity;
    void resize();
public:
    Queue():elements(new T[10]),front(0),rear(0),capacity(10){}
    ~Queue();
    void enqueue(T data);
    T dequeue();
    T getFront() const;
    int getSize() const;
    bool empty() const;

    // - test function: print
    void print(){
        for(int i=0;i<rear - front;++i){
            cout<<elements[i]<<endl;
        }
    }
};

// - resize
template<typename T>
void Queue<T>::resize(){
    T* new_elements = new T[capacity*2];
    for(int i=0;i<=rear;++i){
        new_elements[i] = elements[i];
    }
    delete[] elements;
    elements = new_elements;
    capacity*=2;
}

// - destory
template<typename T>
Queue<T>::~Queue(){
    delete[] elements;
}

// - enqueue
template<typename T>
void Queue<T>::enqueue(T data){
    if(rear == capacity){
        resize();
    }
    elements[rear++] = data;
}

// - dequeue
template<typename T>
T Queue<T>::dequeue(){
    T data = elements[front++];
    return data;
}

// - getFront
template<typename T>
T Queue<T>::getFront() const{
    if(rear == front){
        throw underflow_error("Queue is empty!");
    }
    return elements[front];
}

// - getSize
template<typename T>
int Queue<T>::getSize() const{
    return rear - front;
}

// - empty
template<typename T>
bool Queue<T>::empty() const{
    if(front == rear) return true;
    else return false;
}

// - 2.以队列为底层容器,实现栈
template<typename T>
class myStack{
private:
    Queue<T> q1; // - main queue
    Queue<T> q2; // - assistant queue
public:
    myStack(){}
    // - push into stack
    void push(T x){
        q1.enqueue(x);
    }
    // - pop out of stack
    T pop(){
        if(q1.empty()){
            throw underflow_error("Stack is empty!");
        }
        while(q1.getSize()>1){
            q2.enqueue(q1.dequeue());
        }
        T result = q1.dequeue();
        while(!q2.empty()){
            q1.enqueue(q2.dequeue());
        }
        return result;
    }
    // - get the top data
    T top(){
        if(q1.empty()){
            throw underflow_error("Stack is empty!");
        }
        while(q1.getSize()>1){
            q2.enqueue(q1.dequeue());
        }
        T result = q1.dequeue();
        q2.enqueue(result);
        while(!q2.empty()){
            q1.enqueue(q2.dequeue());
        }
        return result;
    }
    // - check if empty
    bool empty(){
        return q1.empty();
    }
    // - test: print the stack
    void print(){
        q1.print();
    }
};

int main(){
    myStack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    int b = stack1.pop();
    int c = stack1.top();
    cout<<c<<endl;
    stack1.print();
}