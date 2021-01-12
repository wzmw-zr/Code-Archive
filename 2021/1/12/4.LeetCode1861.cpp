/*************************************************************************
	> File Name: 4.LeetCode1861.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月12日 星期二 14时51分59秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<int> findClosedNumbers(int num) {
    int cnt = __builtin_popcount(num);
    int ind = __builtin_ffs(num);
    cout << cnt << " " << ind << endl;
    int mmax = num;
    int mmin = num;
    if (ind == 1) mmin = -1;
    else {
        mmin &= ~(1 << (ind - 1));
        mmin |= (1 << (ind - 2));
    }
    int flag = 0;
    for (int i = ind; i <= 30; i++) {
        if (num & (1 << i)) continue;
        flag = 1;
        mmax &= ~(1 << (ind - 1));
        mmax |= (1 << i);
        break;
    }
    if (!flag) mmax = -1;
    return vector<int>({mmax, mmin});
}

int main() {
    int num;
    cin >> num;
    auto ans = findClosedNumbers(num);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
