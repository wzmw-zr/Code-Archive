/*************************************************************************
	> File Name: 3.Human.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月25日 星期六 16时20分53秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

class People {
    // friend function
    friend int main();
    int x, y;
public:
    void set(int x);
    void say();
};

struct People2 {
    int x, y;
};

void People::set(int x) {
    cout << "set function : " << this << endl;
    this->x = x;
    return ;
}

void People::say() {
    cout << this->x << " " << this->y << endl;
}

int main() {
    People a;
    People2 b;
    a.y = 18432;
    cout << "a object : " << &a << endl;
    a.set(3);
    b.x = 4;
    cout << b.x << endl;
    return 0;
}
