// - 为方便操作,特设俩指针,base指向栈底,top指向栈顶之上(最后一个元素之后)
// - 顺序栈优点:简单方面,缺点:容易溢出
// - 异常:上溢-栈满后压入元素,下溢-栈空后弹出元素
#include<iostream>

#define MAXSIZE 20

using namespace std;

template<typename T>
class stack{
private:
    int base;
    int top;
    T* data;
    int stackSize;
public:
    stack();
    ~stack();
    void resize();
    void clearStack();
    bool stackEmpty();
    bool stackFull();
    int stackLength();
    void push(T a);
    T pop();
    T getTop();
};

// - 构造新栈
template<typename T>
stack<T>::stack(){
    base = 0, top = 0, stackSize = MAXSIZE;
    T* data = new T[MAXSIZE];
}
// - 销毁栈
template<typename T>
stack<T>::~stack(){
    delete[] data;
}
//- 栈扩容
template<typename T>
void stack<T>::resize(){
    int newSize = stackSize*2;
    T* newData = new T[newSize];
    for(int i=0;i<stackSize;++i){
        newData[i] = data[i];
    }
    delete[] data;
    stackSize = newSize;
    data = newData;
}
// - 清空栈
template<typename T>
void stack<T>::clearStack(){
   top = base;
}
// - 栈判空
template<typename T>
bool stack<T>::stackEmpty(){
    if(base == top) return true;
    return false;
}
// - 栈判满
template<typename T>
bool stack<T>::stackFull(){
    if(top == stackSize) return true;
    return false;
}
// - 返回长度
template<typename T>
int stack<T>::stackLength(){
    if(top == base) return 0;
    return top;
}
// - 入栈
template<typename T>
void stack<T>::push(T a){
    bool judge = stackFull();
    if(judge){
        resize();
    }
    data[top++] = a;
}
// - 弹栈
template<typename T>
T stack<T>::pop(){
    if(stackEmpty()){
        throw underflow_error("Stack is empty!");
    }
    T rubbish = data[--top];
    return rubbish;
}
// - 获取栈顶元素
template<typename T>
T stack<T>::getTop(){
    return data[top-1];
}

int main(){
    
}