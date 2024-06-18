#include<iostream>
#include<stdexcept>

using namespace std;

// - 1.stack声明
template<typename T>
class stack{
private:
    struct Node{
        T data;
        Node* next;
        Node(T value):next(nullptr),data(value){}
    };
    int size;
    Node* head;
public:
    stack():size(0),head(nullptr){}
    ~stack();
    void push(T value);
    T pop();
    T top() const;
    int getSize() const;
};

// - 2.stack函数实现
// - 2-1.入栈函数
template<typename T>
void stack<T>::push(T value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    ++size;
}

// - 2-2.弹栈函数
template<typename T>
T stack<T>::pop(){
    if(head == nullptr){
        throw underflow_error("Stack is empty!");
    }
    Node* temp = head;
    T get = temp->data;
    head = head->next;
    delete temp;
    --size;
    return get;
}

// - 2-3.获取栈顶元素
template<typename T>
T stack<T>::top() const{
    if(head == nullptr){
        throw underflow_error("Stack is empty!");
    }
    return head->data;
}

// - 2-4.获取栈元素个数
template<typename T>
int stack<T>::getSize() const{
    return size;
}

// - 3.销毁栈
template<typename T>
stack<T>::~stack(){
    while(head!=nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// - 4.测试区
int main(){
    
}