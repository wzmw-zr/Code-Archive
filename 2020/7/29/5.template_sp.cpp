/*************************************************************************
	> File Name: 5.template_sp.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月29日 星期三 22时55分04秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

template<typename T>
T add(T a, T b) {
    cout << "add function : " << sizeof(T) << endl; 
    return a + b;
}

template<>
int add(int a, int b) {
    cout << "specific template add function" << endl;
    return a + b;
}

template<typename T>
T add(T *a, T *b) {
    cout << "T * : partial template add function" << endl;
    return (*a) + (*b);
}

template<typename T>
class Array {
public:
    Array(int n) : n(n) {
        this->arr = new T[n];
    }

    T &operator[](int ind) {
        if (ind < 0 || ind >= n) return this->__end;
        return this->arr[ind];
    }

    template<typename U>
    friend ostream &operator<<(ostream &out, const Array<U> &a);

private:
    T *arr;
    T __end;
    int n;
};

template<>
class Array<double> {
public:
    Array(int n) : n(n) {
        cout << "double array template" << endl;
        this->arr = new double[n];
    }

    double &operator[](int ind) {
        if (ind < 0 || ind >= n) return this->__end;
        return this->arr[ind];
    }

    template<typename T>
    friend ostream &operator<<(ostream &out, const Array<T> &a);

private:
    double *arr;
    double __end;
    int n;
};


template<typename T>
ostream &operator<<(ostream &out, const Array<T> &a) {
    out << "Class Array : ";
    for (int i = 0; i < a.n; i++) {
        out << a.arr[i] << " ";
    }
    return out;
}

int main() {
    int a_num = 123, b_num = 456;
    cout << add(2, 3) << endl;
    cout << add(2.3, 4.5) << endl;
    cout << add<double>(2.3, 5) << endl;
    cout << add(&a_num, &b_num) << endl;
    Array<int> a(10);
    Array<double> b(10);
    a[0] = 123;
    a[-123] = 456;
    for (int i = 0; i < 10; i++) {
        b[i] = (rand() % 100) / 100.0;
    }
    cout << a << endl;
    cout << b << endl;
    return 0;
}

