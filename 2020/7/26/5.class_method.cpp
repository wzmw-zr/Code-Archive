/*************************************************************************
	> File Name: 5.class_method.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月26日 星期日 19时44分24秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

class Point {
public:
    Point() {
        cout << "constructor : " << this << endl;
        Point::total_cnt += 1;
    }

    Point(const Point &b) : Point() {
        cout << "copy constructor : " << this << endl;
        this->x = b.x;
        this->y = b.y;
    }

    Point(double z) : Point() {
        cout << "convert constructor : " << this << endl;
        this->x = 99, this->y = 99;
    }

    Point(int x, int y) : Point() {
        cout << "parameter constructor : " << this << endl;
        this->x = x;
        this->y = y;
    }

    ~Point() {
        cout << "destructor : " << this << endl;
        Point::total_cnt -= 1;
    }

    void operator=(const Point &b) {
        cout << "operator = " << this << endl;
        this->x = b.x;
        this->y = b.y;
    }

    static int T() { return Point::total_cnt; }

private:
    int x, y;
    static int total_cnt;
};

int Point::total_cnt = 0;

void test() {
    Point a;
    cout << Point::T() << endl;
    return ;
}

int main() {
    Point a;
    cout << a.T() << endl;
    test();
    Point b;
    cout << b.T() << endl;
    Point c(2, 3);
    cout << c.T() << endl;
    Point d(3.14);
    cout << d.T() << endl;
    c = 5.6;
    cout << c.T() << endl;
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    cout << &d << endl;
    return 0;
}
