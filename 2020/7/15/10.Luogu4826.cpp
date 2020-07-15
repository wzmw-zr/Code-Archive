/*************************************************************************
	> File Name: 10.Luogu4826.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月15日 星期三 20时31分52秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define MAX_N 2000

int n;
int id[MAX_N + 5];

int get_val(int x, int y) {
    return x ^ y;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> id[i];

    #if 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            edge[edge_cnt].from = i;
            edge[edge_cnt].to = j;
            edge[edge_cnt].val = i ^ j;
            edge_cnt++:
        }
    }
    #endif
    return 0;
}

