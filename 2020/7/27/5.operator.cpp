/*************************************************************************
	> File Name: 5.operator.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月27日 星期一 19时21分32秒
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
    Point() : __x(0), __y(0) {}
    Point(int x, int y) : __x(x), __y(y) {}
    int x() const { return this->__x; }
    int y() const { return this->__y; }

    Point operator+(const Point &a) {
        return Point(this->__x + a.x(), this->__y + a.y());
    }

    Point &operator+=(const Point &a) {
        this->__x += a.x();
        this->__y += a.y();
        return *this;
    }

    Point &operator++() {
        this->__x += 1;
        this->__y += 1;
        return *this;
    }

    // pass int just to distinguish pre++, and later++
    Point operator++(int) {
        Point temp(*this);
        this->__x += 1;
        this->__y += 1;
        return temp;
    }

private:
    int __x, __y;
};

ostream &operator<<(ostream &out, const Point &a) {
    cout << "Point (" << a.x() << ", " << a.y() << ")";
    return out;
}

int main() {
    Point a(4, 5), b(3, 4), c(1, 1);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << a + b << endl;
    c += b;
    cout << c << endl;
    cout << ++(c += b) << endl;
    cout << c++ << endl;
    cout << c << endl;
    return 0;
}
