#include <iostream>
#include <stdexcept>

using namespace std;

// - 1.队列的声明
template<typename T>
class Queue{
private:
    struct Node{
        T data;
        Node* next;
        Node(T value):data(value),next(nullptr){}
    };
    Node* front;
    Node* rear;
    int size;
public:
    Queue():front(nullptr),rear(nullptr),size(0){};
    ~Queue();
    void enqueue(T value);
    T dequeue();
    T getFront() const;
    int getSize() const;
    void print();
};

// - 2.队列函数实现
// - 2.1 入队函数
template<typename T>
void Queue<T>::enqueue(T value){
    // - 入队
    if(size == 0){
        Node* new_node = new Node(value);
        front = new_node;
        rear = new_node;
    }else{
        Node* temp = rear;
        Node* new_node = new Node(value);
        temp->next = new_node;
        rear = new_node;
    }
    // - 更新队列长度
    size++;
}
// - 2.2 出队函数
template<typename T>
T Queue<T>::dequeue(){
    // 出队
    Node* temp = front;
    front = temp->next;
    T store = temp->data;
    delete temp;
    // 更新队列长度
    size--;
    // - 返回储存值
    return store;
}
// - 2.3 获取队头元素
template<typename T>
T Queue<T>::getFront() const{
    return front->data;
}
// - 2.4 返回队列长度
template<typename T>
int Queue<T>::getSize() const{
    return size;
}
// - 2.5 打印队列
template<typename T>
void Queue<T>::print(){
    Node* curr = front;
    while(curr!=nullptr){
        cout<<curr->data<<endl;
        curr = curr->next;
    }
}
// - 3.队列的销毁
template<typename T>
Queue<T>::~Queue(){
    Node* curr = front;
    while(curr!=nullptr){
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

// - test zone
int main(){
    Queue<int> test;
    test.enqueue(1);
    test.enqueue(2);
    test.enqueue(3);
    test.enqueue(4);
    int a = test.getFront();
    cout<<a<<endl;
    
    test.print();
}
