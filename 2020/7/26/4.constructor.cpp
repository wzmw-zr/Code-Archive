/*************************************************************************
	> File Name: 4.constructor.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月26日 星期日 18时15分34秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

class People {
public:
    People() {}

    People(string name) {
        cout << "parameter constructor : " << name << endl;
        this->name = name;
    }

    People(int x) {
        cout << "init parameter" << endl;
        cout << this->x << endl;
        this->x = x;
    }

    People(const People &b) {
        cout << "copy constructor" << endl;
        this->name = b.name;
        this->x = b.x;
    }

    ~People() {
        cout << "destructor" << endl;
    }

    void operator=(const People &a) {
        this->name = a.name;
        this->x = a.x;
    }

friend int main();
private:
    string name;
    int x;
};

int main() {
    People a;
    People b("zhaorui");
    People c(543);
    People d = 678;
    People e = d; 
    e = c;
    c = 999;
    d = string("zhao rui");
    cout << b.name << endl;
    cout << "hello world" << endl;
    return 0;
}
