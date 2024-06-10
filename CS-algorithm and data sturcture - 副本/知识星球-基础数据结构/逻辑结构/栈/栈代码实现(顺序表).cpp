#include <iostream>
#include <stdexcept>

using namespace std;

// - 1.栈的声明
template<typename T>
class stack{
private:
    T *data;  // - 顶栈指针
    int size;
    int capacity;
    void resize();  // - 扩容函数

public:
    stack():data(new T[capacity]),size(0),capacity(10){};
    ~stack();
    void push(T element); // - 压栈函数
    T pop();              // - 弹栈函数
    T top() const;        // - 获得栈顶元素
    int getSize() const;  // - 得到栈元素个数
};

// - 2-1.扩容函数
template<typename T>
void stack<T>::resize(){
    // - 扩容
    int newCapacity = capacity*2;
    T *newData = new T [newCapacity];
    // - 元素转移
    for(int i=0;i<capacity;++i){
        newData[i] = data[i];
    }
    // - 变量交接
    delete[] data;
    data = newDate;
    capacity = newCapacity;
}

// - 2-2.入栈
template<typename T>
void stack<T>::push(T element){
    if(size == capacity){
        resize();
    }
    data[size++] = element;
}

// - 2-3.出栈
template<typename T>
T stack<T>::pop(){
    if(size == 0){
        throw underflow_erroe("Stack is empty!");
    }
    return data[size--];
}

// - 2-4.获得栈顶元素
template<typename T>
T stack<T>::top() const {
    if(size == 0){
        throw underflow_error("Stack is empty!");
    }
    return data[size-1];
}

// - 2-5.获得栈的元素个数
template<typename T>
int stack<T>::getSize() const{
    return size;
}

// - 3.栈的销毁 
template<typename T>
stack<T>::~stack(){
    delete[] data;
}
