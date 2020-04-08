/*************************************************************************
	> File Name: 2.HZOJ531.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月08日 星期三 18时40分20秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

typedef struct Node {
    int status, step;
} Node;

int n;
int s;
int mmap[25];

int main() {
    cin >> n;
    queue<Node> que;
    int st;
    for (int i = 1; i <= n; i++) {
        cin >> st;
        s |= (1 << st);
    }
    que.push({s, 0});
    for (int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 1; j <= cnt; j++) {
            int num;
            cin >> num;
            mmap[i] |= (1 << num);
        }
    }
    while (!que.empty()) {
        Node tmp = que.front(); 
        que.pop();
        for (int i = 0; i < n; i++) {
            if ((tmp.status >> i) & 1)  
        }
    }
    return 0;
}
