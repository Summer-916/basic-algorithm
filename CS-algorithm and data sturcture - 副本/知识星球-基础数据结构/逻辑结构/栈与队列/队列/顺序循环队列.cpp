#include<iostream>

#define MAXSIZE 100

using namespace std;

template<typename T>
class queue{
private:
    T* data;
    int front;
    int rear;
    int size;
public:
    queue();
    ~queue();
    void resize();
    int getLength();
    void enqueue(T a);
    T dequeue();

};

// - 队列初始化
template<typename T>
queue<T>::queue(){
    front = 0, rear = 0, size = MAXSIZE;
    data = new T[MAXSIZE];
}
// - 销毁队列
template<typename T>
queue<T>::~queue(){
    delete[] data;
}
// - 队列扩容
template<typename T>
void queue<T>::resize(){
    T* newData = new T[size*2];
    size*=2;
    for(int i=front;i<rear;++i){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}
// - 获取队长
template<typename T>
int queue<T>:: getLength(){
    return rear - front;
}
// - 入队
int main(){

}