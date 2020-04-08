/*************************************************************************
	> File Name: 8.HZOJ66.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月08日 星期三 23时13分01秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct Node {
    int x, len;
} Node;

queue<Node> que;
int max_len, cnt = 1000000 - 1;

int main() {
    que.push({1, 1});
    while (!que.empty()) {
        Node tmp = que.front();
        que.pop();
        if (tmp.x < 1000000) {
            cnt--;
            max_len = max(max_len, tmp.len);
        }
        if (!cnt) {
            cout << tmp.x << endl;
            break;
        }
        que.push({tmp.x * 2, tmp.len + 1});
        if ((tmp.x - 1) && !((tmp.x - 1) % 3)) que.push({((tmp.x - 1) / 3), tmp.len + 1});
    }
    return 0;
}
