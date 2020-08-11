/*************************************************************************
	> File Name: main.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月08日 星期六 19时55分00秒
 ************************************************************************/

#include<iostream>
#include "./thread_pool.h"
using namespace std;

void func(int x, int &n) {
    cout << "func : " << x << " " << n << endl;
    n += 2;
}

int main() {
    int n = 123;
    haizei::Task t(func, 23, ref(n));
    t.run();
    cout << n <<  endl;
    return 0;
}
