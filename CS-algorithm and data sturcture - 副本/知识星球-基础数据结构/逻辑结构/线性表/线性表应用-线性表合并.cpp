#include<iostream>
#include<string>

using namespace std;

struct elemtype{
    int coefficient;
    int power;
    elemtype(){}
    elemtype(int a,int b):coefficient(a),power(b){}
};

struct listNode{
    elemtype data;
    listNode* next;    
};

class singleList{
private:
    listNode* head;
    listNode* rear; // - 尾指针,为配合循环链表
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
    void printPolynomial();
    listNode* getRear();
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
        if(curr->data.coefficient == a.coefficient && curr->data.power == a.power) return curr;
        curr = curr->next;
    }
    return nullptr;
}
// - 按值查找,返回索引
int singleList::indexSearch(elemtype a){
    int index = 0;
    listNode* curr = head->next;
    while(curr!=nullptr){
        index++;
        if(curr->data.coefficient == a.coefficient && curr->data.power == a.power) return index;
        curr = curr->next;
    }
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
// - 为尾指针赋值
listNode* singleList::getRear(){
    listNode* curr = head;
    while(curr->next!=nullptr){
        curr = curr->next;
    }
    rear = curr;
    rear->next = head->next;
    return rear;
}
// - 测试函数
void singleList::printPolynomial(){
    listNode* curr = head->next;
    if(curr){
        if(curr->data.coefficient == 1) cout<<"x^"<<curr->data.power;
        else if(curr->data.coefficient == -1) cout<<"-x^"<<curr->data.power;
        else cout<<curr->data.coefficient<<"x^"<<curr->data.power;
        curr = curr->next;
        while(curr){
            if(curr->data.coefficient == -1) cout<<"-x^"<<curr->data.power;
            else if(curr->data.coefficient == 1) cout<<"x^"<<curr->data.power;
            else if(curr->data.coefficient<0) cout<<curr->data.coefficient<<"x^"<<curr->data.power;
            else cout<<"+"<<curr->data.coefficient<<"x^"<<curr->data.power;
            curr = curr->next;
        }
    }
    cout<<endl;
}

// - 头插法建立单链表
// - 时间复杂度:O(1)
void createList_h(int n, singleList &a){
    listNode* head = a.getHead();
    for(int i=0;i<n;++i){
        listNode* newNode = new listNode;
        cin>>newNode->data.coefficient;
        cin>>newNode->data.power;
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
        cin>>newNode->data.coefficient;
        cin>>newNode->data.power;
        t->next = newNode;
        t = newNode;
        a.lengthIncrease();
    }
    t->next = nullptr;
}
// - 线性表合并
void merge(singleList &A,singleList &B){
    int b_length = B.listLength();
    int a_length = A.listLength();
    int b_pivot = 1;
    while(b_pivot!=b_length+1){
        elemtype mid = B.getValue(b_pivot);
        listNode* judge = A.addressSearch(mid);
        if(!judge){
            A.listInsert(a_length+1,mid);
            a_length++;
            b_pivot++;
        }else b_pivot++;
    }
}
// - 有序表合并
void orderListMerge(singleList &A,singleList &B,singleList &C){
    int a_length = A.listLength();
    int b_length = B.listLength();
    int a_pivot = 1, b_pivot = 1, c_pivot = 1;
    while(a_pivot!=a_length+1&&b_pivot!=b_length+1){
        elemtype a_mid = A.getValue(a_pivot);
        elemtype b_mid = B.getValue(b_pivot);
        int a_coefficient = a_mid.coefficient, b_coefficient = b_mid.coefficient;
        if(a_coefficient>b_coefficient){
            C.listInsert(c_pivot, b_mid);
            c_pivot++,b_pivot++;
        }else if(a_coefficient<b_coefficient){
            C.listInsert(c_pivot, a_mid);
            c_pivot++,a_pivot++;
        }else{
            C.listInsert(c_pivot, a_mid);
            C.listInsert(c_pivot, b_mid);
            c_pivot+=2,a_pivot++,b_pivot++;
        }
    }
    if(a_pivot<a_length+1){
        for(int i=a_pivot;i<a_length+1;++i){
            elemtype A_mid = A.getValue(i); 
            C.listInsert(c_pivot, A_mid);
            c_pivot++;
        }
    }else if(b_pivot<b_length+1){
        for(int i=b_pivot;i<b_length+1;++i){
            elemtype B_mid = B.getValue(i);
            C.listInsert(c_pivot, B_mid);
            c_pivot++; 
        }
    }
}
// - 稀疏多项式加减法实现
void polynomialAddition(singleList &A,singleList &B,singleList &C){
    int a_length = A.listLength(), b_length = B.listLength();
    int a_pivot = 0, b_pivot = 0, c_pivot = 0;
    while(a_pivot<=a_length&&b_pivot<=b_length){
        elemtype a_mid = A.getValue(a_pivot), b_mid = B.getValue(b_pivot);
        int a_power = a_mid.power, b_power = b_mid.power;
        if(a_power<b_power){
            C.listInsert(c_pivot, a_mid);
            a_pivot++,c_pivot++;
        }else if(a_power>b_power){
            C.listInsert(c_pivot, b_mid);
            c_pivot++,b_pivot++;
        }else{
            a_pivot++,b_pivot++;
            int a_coefficient = a_mid.coefficient, b_coefficient = b_mid.coefficient;
            if(a_coefficient+b_coefficient){
                elemtype c_mid(a_coefficient+b_coefficient, a_power);
                C.listInsert(c_pivot, c_mid);
                c_pivot++;
            }
        }
    }
    if(a_pivot<=a_length){
        for(int i=a_pivot;i<=a_length;++i){
            elemtype A_mid = A.getValue(i);
            C.listInsert(c_pivot, A_mid);
            c_pivot++;
        }
    }else if(b_pivot<=b_length){
        for(int i=b_pivot;i<=b_length;++i){
            elemtype B_mid = B.getValue(i);
            C.listInsert(c_pivot, B_mid);
            c_pivot++;
        }
    }
}
int main(){
    singleList A,B,C;
    createList_t(5,A);
    createList_t(5,B);
    A.printPolynomial();
}