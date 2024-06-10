// 顺序表示中,逻辑位序 = 物理位序 + 1
#include<iostream>
#include<string>

#define MAXSIZE 20

using namespace std;

class L{
private:
    string name;
    string number;
    string gender;

public:
    L(string a,string b,string c):name(a),number(b),gender(c){}
    L():name("0"),number("0"),gender("0"){}
    string getNumber();
};


string L::getNumber(){
    return number;
}

class sq_linear_list{
private:
    L* sq_list;
    int length;
    int capacity;

public:
    sq_linear_list();           // - 初始化线性表
    ~sq_linear_list();          // - 销毁线性表
    void enlargeList();         // - 扩容线性表
    void clearList();           // - 清空线性表
    int getLength();            // - 获取长度
    bool isEmpty();             // - 判断空或否
    L getElem(int i);           // - 取第i个元素
    int locateElem(string a);   // - 按值查找
    void listInsert(int b,L a); // - 元素插入
    void listDelete(int a);     // - 元素删除
    void listPrint();           // - 元素遍历
};


// - 初始化线性表
sq_linear_list::sq_linear_list(){
    sq_list = new L[MAXSIZE];
    length = 0;
    capacity = 1;
}
// - 扩容线性表
void sq_linear_list::enlargeList(){
    L* new_list = new L[length*2];
    for(int i=0;i<length;++i){
        new_list[i] = sq_list[i];
    }
    delete[] sq_list;
    sq_list = new_list;
    capacity*=2;
}
// - 销毁线性表
sq_linear_list::~sq_linear_list(){
    delete[] sq_list;
}
// - 清空线性表
void sq_linear_list::clearList(){
    length = 0;
}
// - 获得长度
int sq_linear_list::getLength(){
    return length;
}
// - 检查空或否 
bool sq_linear_list::isEmpty(){
    if(length) return false;
    return true;
}
// - 获取元素
// - 时间复杂度:O(1)
L sq_linear_list::getElem(int i){
    if(i<1||i>length){
        throw underflow_error("Out of range!");
    }
    return sq_list[i-1];
} 
// - 顺序查找
// - ASL = (n+1)/2 
// - 平均查找长度 ASL(Average Search Length) ASL = ∑P*C P为元素出现概率,C为查找次数
int sq_linear_list::locateElem(string a){
    for(int i=0;i<length;++i){
        if(sq_list[i].getNumber() == a) return i+1;
    }
    return 0;
}
// - 插入元素
// - 时间复杂度O(n)
void sq_linear_list::listInsert(int b,L a){
    if(b<1||b>length+1){
        throw underflow_error("Out of range!");
    }
    if(length == capacity) enlargeList();
    for(int i=length-1;i>=b-1;--i){
        sq_list[i+1] = sq_list[i];
    }
    sq_list[b-1] = a;
    length++;
}
// - 删除元素
// - 时间复杂度O(n)
void sq_linear_list::listDelete(int a){
    if(a<1||a>length){
        throw underflow_error("Out of range!");
    }
    for(int i=a-1;i<length-1;++i){
        sq_list[i] = sq_list[i+1];
    }
    length--;
}
// - 遍历元素
void sq_linear_list::listPrint(){
    for(int i=0;i<length;++i){
        cout<<sq_list[i].getNumber()<<endl;
    }
}

int main(){
    sq_linear_list lib;
    L a("1","1","1");
    L b("2","2","2");
    L c("3","3","3");
    L d("4","4","4");
    L e("5","5","5");
    lib.listInsert(1,a);
    lib.listInsert(2,b);
    lib.listInsert(3,c);
    lib.listInsert(4,d);
    lib.listPrint();
    lib.listDelete(2);
    lib.listPrint();
    lib.listInsert(3,e);
    lib.listPrint();
}