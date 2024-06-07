#include<iostream>
#include<cstring>

using namespace std;

// - 1.定义数据结构-串
class String{
private:
    size_t length;
    char* str;
public:
    // - 串的创建于销毁
    String();
    String(const char* s); // - 意味着传入的是一个字符串字面量
    String(const String& s);
    ~String();
    // - 串的功能接口
    size_t getSize() const; // - 获取串长度
    char operator[](size_t index) const; // - 重载运算符 - []
    String &operator=(const String &s); // - 重载赋值运算符，将另一个String赋值给当前String
    bool operator==(const String &s) const; // - 重载等于运算符,比较两个字符串是否相等
    bool operator!=(const String &s) const; // - 重载等于运算符,比较两个字符串是否相等
    String copy() const; // - 字符串拷贝
    String operator+(const String &s) const; // -字符串拼接
    friend ostream &operator<<(ostream &out,const String &s); // - 字符串输出  
};

// - 1-1.字符串创建
String::String(){
    length = 0;
    str = new char[1];
    str[0] = '\0';
}

String::String(const char* s){
    length = strlen(s);
    str = new char[length+1];
    strcpy(str,s);
}

String::String(const String& s){
    length = s.getSize();
    str = new char[length+1];
    strcpy(str,s.str);
}

String::~String(){
    delete[] str;
}

// - 1-2.获取串的长度
size_t String::getSize() const{
    return length;
}

// - 1-3.索引取值
char String::operator[](size_t index) const{
    return str[index];
}

// - 1-4.String赋值
String& String::operator=(const String &s){
    if(this!=&s){
        delete[] str;
        length = s.length;
        str = new char[length+1];
        strcpy(str,s.str);
    }
    return *this;
}

// - 1-5.判断是否相等
bool String::operator==(const String &s) const{
    return strcmp(str,s.str) == 0;
}

bool String::operator!=(const String &s) const{
    return strcmp(str,s.str)!=0;
}

// - 1-6.字符串拷贝
String String::copy() const{
    String s = *this;
    return s;
}

// - 1-7.字符串拼接
String String::operator+(const String &s) const{
    String result;
    result.length = length + s.length;
    result.str = new char[result.length+1];
    strcpy(result.str,str);
    strcat(result.str,s.str);
    return result;
}

// - 1-8.字符串输出
ostream& operator<<(ostream& out,const String &s){
    out<<s.str;
    return out;
}

int main(){
    String s1("114514");
    String s2(s1);
    String s3;
    s3 = s1;
    cout<<s3;
}