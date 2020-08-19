/*************************************************************************
	> File Name: 2.stl.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月21日 星期二 19时52分39秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

int main() {
    string s1 = "hello" , s2 = "world";
    s1 += " ";
    s1 += s2;
    cout << s1 << endl;
    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << endl;
    }
    #if 0
    int op, val;
    queue<int> que;
    while (cin >> op >> val) {
        switch (op) {
            case 1: que.push(val); break;
            case 2: que.pop(); break;
            case 3: cout << que.front() << endl; break;
        }
        cout << "queue size = " << que.size() << ", empty : " << (que.empty() ? "true" : "false") << endl;
        printf("queue size = %d, empty : %s\n", que.size(), (que.empty() ? "true" : "false"));
    }
    #endif
    return 0;
}
