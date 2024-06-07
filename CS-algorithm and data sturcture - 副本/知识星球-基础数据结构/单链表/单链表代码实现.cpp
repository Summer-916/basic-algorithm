#include <iostream>
using namespace std;

#define eletype int // 获取其他数据的单链表，只需修改此处

// 1.节点定义
struct listNode{
    eletype data;
    listNode* next;
    listNode(eletype ini):data(ini),next(nullptr){}
};

// 2.单链表声明(类)
class linkedList{
private:
    listNode* head;
    int size;
public:
    linkedList():size(0),head(nullptr){}
    ~linkedList();
    void insert(int index, eletype value); // 插入节点
    void remove(int index);                // 移除节点
    listNode* find(eletype value);         // 检索节点值
    listNode* get(int index);                  // 获取索引节点地址
    void update(int index, eletype value);     // 修改值
    void print();                          // 打印单链表
};

// 2-1 插入节点实现
void linkedList::insert(int index, eletype value){
    // 检查索引是否合法
    if(index<0||index>size){
        throw out_of_range("Invalid Index!");
    }
    // 插入新节点
    if(index == 0){
        listNode* new_node = new listNode(value);
        listNode* temp = head;
        head = new_node;
        head->next = temp;
    }else{
        listNode* new_node = new listNode(value);
        listNode* curr = head;
        for(int i=0;i<index-1;++i){
            curr = curr->next;
        }
        listNode* temp = curr->next;
        curr->next = new_node;
        curr->next->next = temp;
    }
    // 更新节点个数
    size++;
}
// 2-2 移除节点实现
void linkedList::remove(int index){
    // 检查索引是否合法
    if(index<0||index>=size){
        throw out_of_range("Invalid index!");
    }
    // 移除节点
    listNode* curr = head;
    for(int i=0;i<index-1;++i){
        curr = curr->next;
    }
    listNode* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    // 
    size --;
    
}
// 2-3 检索值实现
listNode* linkedList::find(eletype value){
    listNode* curr = head;
    while(curr!=nullptr){
        if(head->data == value) return curr;
        curr = curr->next;
    }
    cout<<"4o4 NO Found!";
    return nullptr;
}
// 2-4 查找值实现
listNode* linkedList::get(int index){
    // 检查索引是否合法
    if(index<0||index>=size){
        throw out_of_range("Invalid index!");
    }
    // 查找节点
    listNode* curr = head;
    for(int i=0;i<index;++i){
        curr = curr->next;
    }
    // 返回节点地址
    return curr;
}
// 2-5 修改值实现
void linkedList::update(int index, eletype value){
    // 检查索引是否合法
    if(index<0||index>=size){
        throw out_of_range("Invalid index!");
    }
    // 修改值
    listNode* curr = get(index);
    curr->data = value;
}
// 2-6 打印单链表
void linkedList::print(){
    listNode* curr = head;
    while(curr!=nullptr){
        cout<<curr->data<<endl;
        curr = curr->next;
    }
}

// 3.单链表的销毁
linkedList::~linkedList(){
    listNode* curr = head;
    while(curr!=nullptr){
        listNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

// 测试区
int main(){
    linkedList test;
    test.insert(0,1);
    test.insert(1,2);
    test.insert(2,3);
    test.insert(3,4);
    test.insert(4,5);
    test.insert(5,6);
    test.insert(1,7);
    test.remove(1);
    
    test.print();
}