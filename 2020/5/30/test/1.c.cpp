/*************************************************************************
	> File Name: 1.c.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月30日 星期六 16时37分46秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
#define MAX_N 300000

int n, k;
int num[MAX_N + 5];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> num[i];
    int ind = 0, cnt = 0, flag = 0;
    deque<int> min_que;
    while (ind < n && cnt < k - 1) {
        while (!min_que.empty() && num[min_que.back()] >= num[ind])
            min_que.pop_back();
        min_que.push_back(ind);
        ind++, cnt++;
    }
    while (ind < n) {
        if (ind - min_que.front() == k) min_que.pop_front(); 
        while (!min_que.empty() && num[min_que.back()] >= num[ind]) 
            min_que.pop_back();
        min_que.push_back(ind);
        flag && cout << " ";
        cout << num[min_que.front()];
        ind++, flag = 1;
    }
    cout << endl;
    ind = 0, cnt = 0, flag = 0;
    deque<int> max_que;
    while (ind < n && cnt < k - 1) {
        while (!max_que.empty() && num[max_que.back()] <= num[ind])
            max_que.pop_back();
        max_que.push_back(ind);
        ind++, cnt++;
    }
    while (ind < n) {
        if (ind - max_que.front() == k) max_que.pop_front(); 
        while (!max_que.empty() && num[max_que.back()] <= num[ind]) 
            max_que.pop_back();
        max_que.push_back(ind);
        flag && cout << " ";
        cout << num[max_que.front()];
        ind++, flag = 1;
    }
    cout << endl;
    return 0;
}
