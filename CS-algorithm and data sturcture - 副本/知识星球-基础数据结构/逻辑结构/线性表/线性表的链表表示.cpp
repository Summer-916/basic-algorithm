#include<iostream>
#include<string>

using namespace std;

struct elemtype{
    int number;
    string name;
    elemtype(){}
    elemtype(int a,string b):number(a),name(b){}
};

struct listNode{
    elemtype data;
    listNode* next;    
};

class singleList{
private:
    listNode* head;
    int length;
public:
    singleList();
    ~singleList();
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
};

// - 单链表初始化
singleList::singleList(){
    head = new listNode;
    head->next = nullptr;
    length = 0;
}
// - 单链表销毁
singleList::~singleList(){
    listNode* curr = head;
    while(curr!=nullptr){
        listNode* mid = curr->next;
        delete curr;
        curr = mid;
    }
}
// - 获取头结点
listNode* singleList::getHead(){
    return head;
}
// - 扩展表长
void singleList::lengthIncrease(){
    length++;
}
// - 判断是否为空
bool singleList::isEmpty(){
    if(head->next == nullptr) return true;
    return false;
}
// - 清空单链表
void singleList::clearList(){
    listNode* curr = head->next;
    while(curr!=nullptr){
        listNode* mid = curr->next;
        delete curr;
        curr = mid;
    }
    head->next = nullptr;
    length = 0;
}
// - 求表长
int singleList::listLength(){
    return length;
}
// - 取值
elemtype singleList::getValue(int a){
    if(a<1||a>length){
        throw underflow_error("Out of range!");
    }
    listNode* curr = head;
    for(int i=1;i<=a;++i){
        curr = curr->next;
    }
    return curr->data;
}
// - 按值查找,返回地址
listNode* singleList::addressSearch(elemtype a){
    listNode* curr = head->next;
    while(curr!=nullptr){
        if(curr->data.number == a.number && curr->data.name == a.name) return curr;
        curr = curr->next;
    }
    cout<<"4O4 Nofounded"<<endl;
    return nullptr;
}
// - 按值查找,返回索引
int singleList::indexSearch(elemtype a){
    int index = 0;
    listNode* curr = head->next;
    while(curr!=nullptr){
        index++;
        if(curr->data.number == a.number && curr->data.name == a.name) return index;
        curr = curr->next;
    }
    cout<<"4O4 Nofounded"<<endl;
    return 0;
}
// - 插入元素
// - 时间复杂度:O(n)
void singleList::listInsert(int a, elemtype b){
    if(a<1||a>length+1){
            throw underflow_error("Out of range!");
        }
    listNode* curr = head;
    for(int i=1;i<=a-1;++i){
        curr = curr->next;
    }
    listNode* newNode = new listNode;
    newNode->data = b;
    newNode->next = curr->next;
    curr->next = newNode;
    length++;
}
// - 删除元素
// - 时间复杂度:O(n)
void singleList::listDelete(int a){
    if(a<1||a>length){
        throw underflow_error("Out of range!");
    }
    listNode* curr = head;
    for(int i=0;i<a-1;++i){
        curr = curr->next;
    }
    listNode* mid = curr->next;
    curr->next = curr->next->next;
    delete mid;
    length--;
}
// - 测试函数
void singleList::listPrintName(){
    listNode* curr = head->next;
    while(curr!=nullptr){
        cout<<curr->data.name<<endl;
        curr = curr->next;
    }
}
void singleList::listPrintNumber(){
    listNode* curr = head->next;
    while(curr!=nullptr){
        cout<<curr->data.number<<endl;
        curr = curr->next;
    }
}

// - 头插法建立单链表
// - 时间复杂度:O(1)
void createList_h(int n, singleList &a){
    listNode* head = a.getHead();
    for(int i=0;i<n;++i){
        listNode* newNode = new listNode;
        cin>>newNode->data.number;
        cin>>newNode->data.name;
        newNode->next = head->next;
        head->next = newNode;
        a.lengthIncrease();
    }
}
// - 尾插法建立单链表
// - 时间复杂度:O(n)
void createList_t(int n,singleList &a){
    listNode* t = a.getHead();
    for(int i=0;i<n;++i){
        listNode* newNode = new listNode;
        cin>>newNode->data.number;
        cin>>newNode->data.name;
        t->next = newNode;
        t = newNode;
        a.lengthIncrease();
    }
    t->next = nullptr;
}
int main(){
    singleList A;
    elemtype a(1,"a"),b(2,"b"),c(3,"c"),d(4,"d"),e(5,"e");
    createList_t(5, A);
    A.listPrintNumber();
}