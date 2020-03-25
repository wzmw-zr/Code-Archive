/*************************************************************************
	> File Name: 4.HZOJ541.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月25日 星期三 19时08分56秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int n, m, atime[2][20][20], a, b, c, d, ans[2][100000], ans_num[2];

void func(int pepole, int locate, int cost) {
    if (locate == n) {
        ans[pepole][ans_num[pepole]] = cost;
        ans_num[pepole]++;
        return ;
    }
    for (int i = locate + 1; i <= n; i++) {
        if (atime[pepole][locate][i]) {
            func(pepole, i, cost + atime[pepole][locate][i]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c >> d;
        atime[0][a][b] = atime[0][b][a] = c;
        atime[1][a][b] = atime[1][b][a] = d;
    }
    func(0, 1, 0);
    func(1, 1, 0);
    sort(ans[0], ans[0] + ans_num[0]);
    sort(ans[1], ans[1] + ans_num[1]);
    for (int i = 0; i < ans_num[0]; i++) {
        for (int j = 0; j < ans_num[1]; j++) {
            if (ans[0][i] == ans[1][j]) {
                cout << ans[0][i] << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
