/*************************************************************************
	> File Name: 4.thread.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月13日 星期四 11时49分46秒
 ************************************************************************/

#include <iostream>
#include <thread>
using namespace std;

void func() {
    cout << "hello world" << endl;
}

void func1(int x) {
    cout << x << " hello world" << endl;
}

void func2(int &x) {
    x += 1;
    cout << x << " " << " helloworld" << endl;
}

int main() {
    thread t1(func);
    thread t2(func);
    thread t3(func);
    t1.join();
    t2.join();
    t3.join();
    thread t4(func1, 4);
    thread t5(func1, 5);
    thread t6(func1, 6);
    t4.join();
    t5.join();
    t6.join();
    int n = 0;
    thread t7(func2, ref(n));
    thread t8(func2, ref(n));
    thread t9(func2, ref(n));
    t7.join();
    t8.join();
    t9.join();
    return 0;
}
