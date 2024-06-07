#include<iostream>

using namespace std;

class complex{
private:
    double real_part;
    double imag_part;
public:
    complex():real_part(0),imag_part(0){}
    complex(double a, double b):real_part(a),imag_part(b){}
    void assign(double r, double i);
    double get_real_part();
    double get_imag_part();
    complex c_add(complex a, complex b);
    complex c_multiple(complex a, complex b);
    complex c_division(complex a, complex b);
    void c_print();
};

void complex::assign(double r, double i){
    real_part = r;
    imag_part = i;
}

double complex::get_real_part(){
    return real_part;
}

double complex::get_imag_part(){
    return imag_part;
}

complex complex::c_add(complex a, complex b){
    real_part = a.get_real_part()+b.get_real_part();
    imag_part = a.get_imag_part()+b.get_imag_part();
}

complex complex::c_multiple(complex a, complex b){
    real_part = a.get_real_part()*b.get_real_part()-a.get_imag_part()*b.get_imag_part();
    imag_part = a.get_real_part()*b.get_imag_part()+a.get_imag_part()*b.get_real_part();
}

complex complex::c_division(complex a, complex b){
    complex d,e,f;
    d.assign(b.get_real_part(),-b.get_imag_part());
    e.c_multiple(a,d);
    f.c_multiple(b,d);
    double g = f.get_real_part();
    real_part = e.get_real_part()/g;
    imag_part = e.get_imag_part()/g;
}

void complex::c_print(){
    if(imag_part<0) cout<<real_part<<imag_part<<"i";
    else cout<<real_part<<"+"<<imag_part<<"i";
}
int main(){
    complex a(-1,2);
    complex b(3,-4);
    complex c;
    c.c_division(a,b);
    c.c_print();
}