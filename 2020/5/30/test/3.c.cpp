/*************************************************************************
	> File Name: 3.c.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月30日 星期六 14时14分54秒
 ************************************************************************/

#include<iostream>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX_N 300000

struct Node {
    int ind, val;
};

int n, k;
Node num[MAX_N + 5];
int min_num[MAX_N + 5], max_num[MAX_N + 5];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> num[i].val;
        num[i].ind = i;
    }
    deque<Node> min_que, max_que;
    int ind = 0, cnt = 0;
    int min_l = 0, max_l = 0;
    int l = 0;
    while (ind < n && cnt < k) {
        while (!min_que.empty()) {
            if (min_que.back().val > num[ind].val) min_que.pop_back();
            else break;
        }
        min_que.push_back(num[ind]);
        while (!max_que.empty()) {
            if (max_que.back().val < num[ind].val) max_que.pop_back();
            else break;
        }
        max_que.push_back(num[ind]);
        cnt++, ind++;
    }
    while (ind < n) {
        min_num[l] = min_que.front().val;
        max_num[l] = max_que.front().val;
        cout << min_num[l] << " " << max_num[l] << endl;
        if (min_que.front().ind - l + 1 >= k) min_que.pop_front(); 
        if (max_que.front().ind - l + 1 >= k) max_que.pop_front(); 
        while (!min_que.empty()) {
            if (min_que.back().val >= num[ind].val) min_que.pop_back();
            else break;
        }
        min_que.push_back(num[ind]);
        while (!max_que.empty()) {
            if (max_que.back().val <= num[ind].val) max_que.pop_back();
            else break;
        }
        max_que.push_back(num[ind]);
        ind++, l++;
    }
    for (int i = 0; i < l; i++) {
        i && cout << " ";
        cout << min_num[i];
    }
    cout << endl;
    for (int i = 0; i < l; i++) {
        i && cout << " ";
        cout << max_num[i];
    }
    cout << endl;
    return 0;
}
