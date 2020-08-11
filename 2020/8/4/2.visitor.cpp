/*************************************************************************
	> File Name: 2.visitor.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月04日 星期二 07时45分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

class B;
class C;
class D;
class E;

class A {
public:
    class IVisitor {
    public:
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
        virtual void visit(D *) = 0;
        virtual void visit(E *) = 0;
    };
    virtual void Accept(IVisitor *) = 0;
    virtual ~A() {}
};

class B : public A {
public:
    virtual void Accept(IVisitor *vis) override {
        vis->visit(this);
    };
};

class C : public A {
public:
    virtual void Accept(IVisitor *vis) override {
        vis->visit(this);
    };
};

class D : public A {
public:
    virtual void Accept(IVisitor *vis) override {
        vis->visit(this);
    };
};

class E : public A {
public:
    virtual void Accept(IVisitor *vis) override {
        vis->visit(this);
    };
};

class OutputVisitor : public A::IVisitor {
public:
    virtual void visit(B *obj) override {
        cout << "this is a class B object" << endl;
    };
    virtual void visit(C *obj) override {
        cout << "this is a class C object" << endl;
    };
    virtual void visit(D *obj) override {
        cout << "this is a class D object" << endl;
    };
    virtual void visit(E *obj) override {
        cout << "this is a class E object" << endl; 
    };
};

int main() {
    A *arr[10];
    for (int i = 0; i < 10; i++) {
        switch (rand() % 4) {
            case 0 : arr[i] = new B(); break;
            case 1 : arr[i] = new C(); break;
            case 2 : arr[i] = new D(); break;
            case 3 : arr[i] = new E(); break;
        }
    }
    OutputVisitor vis;
    for (int i = 0; i < 10; i++) {
        arr[i]->Accept(&vis);
    }
    return 0;
}
