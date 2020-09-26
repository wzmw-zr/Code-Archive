/*************************************************************************
	> File Name: 1.GPA.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月26日 星期六 15时03分29秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

#define MAX_N 20

int t, n;
int a[MAX_N + 5], p[MAX_N + 5];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> p[i];
        for (int i = 0; i < n; i++) ans += p[i] * a[i];
        ans *= 4;
        if (ans > 39900) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
    return 0;
}
