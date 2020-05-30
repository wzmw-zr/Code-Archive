/*************************************************************************
	> File Name: 6.f.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月30日 星期六 15时15分28秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

int n;
int a, b;

void func() {
    cin >> a >> b;
    cout << a <<  " " << (b / 2 + (b & 1)) << endl;
    int n, cnt = 0;
    priority_queue<int> max_que;
    priority_queue<int, vector<int>, greater<int>> min_que;
    for (int i = 1; i <= b; i++) {
        cin >> n;
        if (max_que.empty()) max_que.push(n);
        else {
            if (max_que.top() >= n) max_que.push(n);
            else min_que.push(n);
        }
        if (max_que.size() == min_que.size()) continue;
        if ((max_que.size() - min_que.size() == 1) || (max_que.size() - min_que.size() == -1)) {
            cnt && cout << " ";
            cnt++;
            if (max_que.size() > min_que.size()) cout << max_que.top();
            else cout << min_que.top();
            if (cnt == 10) {
                cnt = 0;
                cout << endl;
            }
            continue;
        }
        if (max_que.size() > min_que.size()) {
            int temp = max_que.top();
            max_que.pop();
            min_que.push(temp);
        } else {
            int temp = min_que.top();
            min_que.pop();
            max_que.push(temp);
        }
    }
    if (cnt) cout << endl;
}

int main() {
    cin >> n;
    while (n--) {
        func();
    }
    return 0;
}
