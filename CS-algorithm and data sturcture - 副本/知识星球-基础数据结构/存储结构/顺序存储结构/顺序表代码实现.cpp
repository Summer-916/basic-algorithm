#include <iostream>
#include <vector>

using namespace std;

// - 1.顺序表的定义
struct sequentialList {
    int *elements; // - 指向首元素的指针
    int size;      // - 顺序表当前的元素个数
    int capacity;  // - 顺序表当前的容量(数组大小)
};
// - 2.顺序表的初始化
void initializeList(sequentialList &List, int capacity){
    List.elements = new int[capacity]; // - 不一定是int
    List.size = capacity;
    List.capacity = capacity;    
}
// - 3.顺序标的销毁
void destoryList(sequentialList &List){
    delete[] List.elements;
}
// - 4.顺序表的元素个数
bool isEmpty(sequentialList &List){
    if(List.size) return true;
    else return false;
}
int getSize(sequentialList &List){
    return List.size;
}
// - 5.顺序表元素插入
void insert(sequentialList &List,int index,int element){
    // - 先检查索引是否有效
    if(index<0||index>List.size){
        throw out_of_range("Invalid index!");
    }
    // - 再检查容量是否满了,如满，加倍容量
    if(List.size == List.capacity){
        int* new_list = new int [List.capacity*2];
        for(int i=0;i<List.capacity;++i){
            new_list[i] = List.elements[i];
        }
        delete[] List.elements;
        List.elements = new_list;
    }
    // - 开始插
    for(int i=List.size;i>=index+1;--i){
        List.elements[i] = List.elements[i-1];  
    }
    List.elements[index] = element;
    // - 更新元素数量
    List.size++;
}
// - 6.顺序表元素删除
void deleteElement(sequentialList &List, int index){
    // - 先检查索引是否合法
    if(index<0||index>List.size){
        throw out_of_range("Invalid index!");
    }
    // - 再删除元素:各元素依次前移
    for(int i=index;i<List.size-1;++i){
        List.elements[i] = List.elements[i+1];
    }
    // - 更新元素个数
    List.size--;
}
// - 7.顺序表元素查找(返回元素索引)
int findElement(sequentialList &List, int element){
    for(int i = 0;i<List.size;++i){
        if(List.elements[i]==element) return i;
    }
    return -1;
}
// - 8.根据索引返回元素(不一定是int)
int getElement(sequentialList &List,int index){
    if(index<0||index>=List.size){
        throw invalid_argument("Invalid index");
    }
    return List.elements[index];
}
// - 9.顺序表元素修改
void updateElement(sequentialList &List, int index,int value){
    if(index<0||index>=List.size){
        throw invalid_argument("Invalid index");
    }
    List.elements[index] = value;
}
// - test zone
int main(){
    sequentialList arr1;
    initializeList(arr1,5);
    insert(arr1,5,11);
    return 0;
}