/*************************************************************************
	> File Name: 1.case.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月12日 星期三 18时12分57秒
 ************************************************************************/

#include<iostream>
using namespace std;

class shape {
    public:
    virtual int area() = 0;
};

class rectange : public shape {
    public:
    int a, b;
    void setLength(int x, int y) {a = x, b = y; };
    int area() { return a * b; }
};

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int *ptr = (int *) (&a + 1);
    for (int i = 0; i < 5; i++) {
        printf("%lld\n", &(a[i]));
    }
    printf("%lld\n", (ptr - 1));
    printf("%d, %d\n", *(a + 1), *(ptr - 1));
    int (*n)[10];
    printf("%d\n", sizeof(n));
    cout << (1, 2, 3, 4, 5) << endl;
    return 0;
}
