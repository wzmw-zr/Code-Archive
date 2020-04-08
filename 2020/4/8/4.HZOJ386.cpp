/*************************************************************************
	> File Name: 4.HZOJ386.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月08日 星期三 19时41分06秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Node {
    int num, val;
} Node;

int m, n;
int y;
Node x[100005];

int cmp(Node a, Node b) {
    return a.val < b.val;
}

int b_s() {
    int l = 1, r = m, mid; 
    while (l <= r) {
        mid = (l + r) >> 1;
        if (x[mid].val == y) return x[mid].num;
        if (x[mid].val < y) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> x[i].val;
        x[i].num = i;
    }
    sort(x + 1, x + m + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cin >> y;
        cout << b_s() << endl;
    }
    return 0;
}
