/*************************************************************************
	> File Name: 6.virtual_table.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月28日 星期二 22时49分27秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Animal {
public:
    Animal() {
        this->x = 8827, this->y = 6523; 
    }

    virtual void say(int x) { 
        cout << "I don't know how to say" << endl; 
    }

    virtual void run() {
        cout << "I don't know how to run" << endl;
    }

protected:
    int x, y;
};

class Cat : public Animal {
public:
    Cat() = default;
    void say(int n) override {
        cout << this << endl;
        cout << this->x << " " << this->y << endl;
        cout << n << endl;
        cout << "miao miao miao" << endl;
    }

    void run() override {
        cout << "I can run with four legs" << endl;
    }
};

void output_raw_data(void *q, int n) {
    unsigned char *p = (unsigned char *) q;
    printf("%p : ", p);
    for (int i = 0; i < n; i++) {
        printf("%02X ", p[i]);
    }
    printf("\n");
    return ;
}

typedef void (*func)(void *, int x);

int main() {
    Cat a, b;
    output_raw_data(&a, sizeof(a));
    output_raw_data(&b, sizeof(b));
    ((func **)(&a))[0][0](&a, 100);
    return 0;
}
