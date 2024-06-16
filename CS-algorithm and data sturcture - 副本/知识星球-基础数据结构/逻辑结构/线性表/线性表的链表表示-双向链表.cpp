#include<iostream>
#include<string>

using namespace std;

struct elemtype{
    int number;
    string name;
    elemtype(int a,string b):number(a),name(b){}
    elemtype(){}
};

struct listNode{
    elemtype data;
    listNode* front;
    listNode* rear;
};

class doubleLinkedList{
private: 
    listNode* head;
    int length;

public:
    doubleLinkedList();
    ~doubleLinkedList();
    listNode* getHead();
    void lengthIncrease();
    bool isEmpty();
    void clearList();
    int listLength();
    elemtype getValue(int a);
    listNode* addressSearch(elemtype a);
    int indexSearch(elemtype a);
    void listInsert(int a, elemtype b);
    void listDelete(int a);
    void listPrintName();
    void listPrintNumber();
    listNode* getRear();

};

// - 链表初始化
doubleLinkedList::doubleLinkedList(){
    length = 0;
    head = new listNode;
    head->front = nullptr;
    head->rear = nullptr;
}
// - 链表销毁
doubleLinkedList::~doubleLinkedList(){
    listNode* curr = head;
    while(curr){
        listNode* mid = curr->rear;
        delete curr;
        curr = mid;
    }
}
// - 获得头指针
listNode* doubleLinkedList::getHead(){
    return head;
}
// - 长度递增
void doubleLinkedList::lengthIncrease(){
    length++;
}
// - 判断空表
bool doubleLinkedList::isEmpty(){
    if(length) return false;
    return true;
}
// - 清空链表
void doubleLinkedList::clearList(){
    listNode* curr = head->rear;
    while(curr){
        listNode* mid = curr->rear;
        delete curr;
        curr = mid;
    }
    head->rear = nullptr;
    length = 0;
}
// - 获得表长
int doubleLinkedList::listLength(){
    return length;
}
// - 访问元素
elemtype doubleLinkedList::getValue(int a){
    if(a<1||a>length){
        throw underflow_error("Out of range!");
    }
    listNode* curr = head;
    for(int i=0;i<a;++i){
        curr = curr->rear;
    }
    return curr->data;
}
// - 按值搜索-返回地址
listNode* doubleLinkedList::addressSearch(elemtype a){
    listNode* curr = head;
    while(curr){
        if(curr->data.number == a.number&&curr->data.name == a.name) return curr;
        curr = curr->rear;
    }
    cout<<"4O4 Nofounded!"<<endl;
    return nullptr;
}
// - 按值搜索-返回位序
int doubleLinkedList::indexSearch(elemtype a){
    int index = 1;
    listNode* curr = head->rear;
    while(curr){
        if(curr->data.number == a.number&&curr->data.name == a.name) return index;
        index++;
        curr = curr->rear;
    }
    cout<<"4O4 Nofounded!"<<endl;
    index = 0;
    return index;
}
// - 插入元素
void doubleLinkedList::listInsert(int a, elemtype b){
    if(a<1||a>length+1){
        throw underflow_error("Out of range!");
    }
    listNode* curr = head;
    for(int i=0;i<a-1;++i){
        curr = curr->rear;
    }
    listNode* newNode = new listNode;
    newNode->data = b;
    newNode->rear = curr->rear;
    curr->rear = newNode;
    newNode->front = curr;
    length++;
}
// - 删除元素
void doubleLinkedList::listDelete(int a){
    if(a<1||a>length){
        throw underflow_error("Out of range!");
    }
    listNode* curr = head;
    for(int i=0;i<a-1;++i){
        curr = curr->rear;
    }
    listNode* mid = curr->rear;
    curr->rear = curr->rear->rear;
    curr->rear->front = curr;
    delete mid;
    length--;
}
// - 测试函数
void doubleLinkedList::listPrintName(){
    listNode* curr = head->rear;
    for(int i=0;i<length;++i){
        cout<<curr->data.name<<endl;
        curr = curr->rear;
    }
}
void doubleLinkedList::listPrintNumber(){
    listNode* curr = head->rear;
    for(int i=0;i<length;++i){
        cout<<curr->data.number<<endl;
        curr = curr->rear;
    }
}

int main(){ 
    doubleLinkedList A;
    elemtype a(1,"a"),b(2,"b"),c(3,"c"),d(4,"d"),e(5,"e");
    A.listInsert(1,a);
    A.listInsert(2,b);
    A.listInsert(3,c);
    A.listInsert(4,d);
    A.listInsert(5,e);
    A.listDelete(3);
    A.listPrintNumber();
}