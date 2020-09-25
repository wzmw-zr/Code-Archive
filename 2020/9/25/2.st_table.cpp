/*************************************************************************
	> File Name: 2.st_table.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月25日 星期五 14时39分49秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

const int logn = 30;
const int maxn = 100010;

int nums[maxn + 5][logn + 5], Logn[maxn + 5];

void init_log() {
    Logn[1] = 0;
    Logn[2] = 1;
    for (int i = 3; i <= maxn; i++) {
        Logn[i] = Logn[i / 2] + 1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> nums[i][0];
    init_log();
    for (int j = 1; j <= logn; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            nums[i][j] = max(nums[i][j - 1], nums[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++) {
        int x, y, s;
        cin >> x >> y;
        s = Logn[y - x + 1];
        cout << max(nums[x][s], nums[y - (1 << s) + 1][s]) << endl;
    }
    return 0;
}
