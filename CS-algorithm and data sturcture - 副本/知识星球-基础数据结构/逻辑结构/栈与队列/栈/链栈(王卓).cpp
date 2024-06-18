#include<iostream>

using namespace std;

template<typename T>
struct listNode{
    T data;
    listNode* next;
};

template<typename T>
class stack{
private:
    listNode* head;
    int length;
public:
    stack();
    ~stack();
    bool stackEmpty();
    void push(T a);
    T pop();
    int getLength();
    T getTop();
};

// - 构造函数
template<typename T>
stack<T>::stack(){
    head = new listNode;
    length = 0;
}
// - 析构函数
template<typename T>
stack<T>::~stack(){
    listNode* curr = head;
    while(curr){
        listNode* mid = curr->next;
        delete curr;
        curr = mid;
    }
}
// - 栈判空
template<typename T>
bool stack<T>::stackEmpty(){
    if(!head->next) return true;
    return false;
}
// - 入栈
template<typename T>
void stack<T>::push(T a){
    listNode* newNode = new listNode;
    newNode.data = a;
    listNode* mid = head->next;
    head->next = newNode;
    newNode->next = mid;
}
// - 弹栈
template<typename T>
T stack<T>::pop(){
    if(!head->next){
        throw underflow_error("Stack is empty!");
    }
    T* mid = head->next.data;
    listNode* curr = head->next;
    head->next = curr->next;
    delete curr;
    return mid;
}
// - 获取栈顶元素
template<typename T>
T stack<T>::getTop(){
    return head->next.data;
}

int main(){
    
}