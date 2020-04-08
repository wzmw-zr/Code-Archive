/*************************************************************************
	> File Name: 3.HZOJ531.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月08日 星期三 19时07分38秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

typedef struct Node {
    int status, step;
} Node;

int n;
int num[25];
int arr[25][25];
int check[2200000];

void init() {
    int t = 1;
    for (int i = 0; i < 21; i++) {
        num[i] = t; 
        t <<= 1;
    }
}

int main() {
    init();
    cin >> n;
    int start_status = 0;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t == 1) start_status += num[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0];
        for (int j = 1; j <= arr[i][0]; j++) {
            cin >> arr[i][j];
            arr[i][24] += num[arr[i][j]];
        }
    }
    queue<Node> que;
    que.push({start_status, 0});
    check[start_status] = 1;
    while (!que.empty()) {
        Node tmp = que.front(); 
        que.pop();
        if (tmp.status == 8) {
            cout << tmp.step << endl;
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if ((tmp.status & num[i]) == 0) {
                int status_temp = tmp.status + num[i];
                status_temp &= ~(arr[i][24]);
                if (!check[status_temp]) {
                    check[status_temp] = 1;
                    que.push({status_temp, tmp.step + 1});
                }
            }
        }
    }
    return 0;
}

