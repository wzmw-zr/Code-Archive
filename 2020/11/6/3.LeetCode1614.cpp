/*************************************************************************
	> File Name: 3.LeetCode1614.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月06日 星期五 13时37分38秒
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

int maxDepth(string s) {
    int ans = 0, cnt = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            cnt++;
            ans = max(ans, cnt);
        } else if (s[i] == ')') cnt--;
        else continue;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << maxDepth(s) << endl;
    return 0;
}
