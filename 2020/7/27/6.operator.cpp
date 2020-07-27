/*************************************************************************
	> File Name: 6.operator.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月27日 星期一 20时05分16秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

class A {
public:
    A() {
        this->arr = new int[10];
    }

    A(const A &a) : A() {
        for (int i = 0; i < 10; i++) {
            this->arr[i] = a.arr[i];   
        }
        this->x = a.x;
        this->y = a.y;
    }

    int *arr;
    int x, y;
};

class B {
public:
    B() : obj(nullptr) {
        arr = new int[10];
        arr[3] = 9973;
    }

    B(A *obj) : B() {
        this->obj = obj;
    }

    int operator()(int a, int b) {
        return a + b;
    }

    int &operator[](int ind) {
        return this->arr[ind];
    }

    void operator[](const char *msg) {
        cout << msg << endl;
        return ;
    }

    A *operator->() {
        return this->obj;
    }

    A &operator*() {
        return *this->obj;
    }
    
    ~B() {
        delete arr;
    }

private:
    int *arr;
    A *obj;
};

ostream &operator<<(ostream &out, A &a) {
    out << "A(" << a.x << ", " << a.y << ")" << endl;
    return out;
}

int main() {
    B add;
    cout << add(3, 4) << endl;
    cout << add[3] << endl;
    add[3] = 8876;
    cout << add[3] << endl;
    add["hello world"];
    A a;
    B p = &a;
    a.x = 67, a.y = 99;
    cout << p->x << " " << p->y << endl;
    cout << *p << endl;

    A c, d(c);
    c.arr[3] = 9973;
    d.arr[3] = 6687;
    cout << c.arr[3] << " " << d.arr[3] << endl;
    return 0;
}
