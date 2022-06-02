#include "std_lib_facilities.h"
//1.fealadat
class B1 {
public:
    virtual void vf() { 
        cout << "B1::vf()\n"; 
    }
    void f() { 
        cout << "B1::f()\n"; 
    }
    virtual void pvf() =0;
};
//2.fealdat
class D1 : public B1 {
public:
    void vf() { cout << "D1::vf()\n"; }
    //4.fealdat
    //void f() { cout << "D1::f()\n"; }
};

//6.feladat
class D2 : public D1 {
public:
    void pvf() { cout << "D2::pvf()\n"; }
};
//7.fealdat
class B2 {
public:
    virtual void pvf() =0;
};

class D21 : public B2 {
public:
    void pvf() { cout << s << endl; }
    string s;
};

class D22 : public B2 {
public:
    void pvf() { cout << n << endl;}
    int n;
};

void f(B2& b2)
{
    b2.pvf();
}



int main() {
    //1.fealadat
    //B1 b1;
    //b1.vf();
    //b1.f();
    //2.fealdat
    //D1 d1;
    //d1.vf();
    //d1.f();
    //3.feladat
    //B1& bref = d1;
    //bref.vf();
    //bref.f();

    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();

    D21 d21;
    d21.s = "Ez a : d21.s";
    D22 d22;
    d22.n = 2022;
    f(d21);
    f(d22);

    return 0;
}