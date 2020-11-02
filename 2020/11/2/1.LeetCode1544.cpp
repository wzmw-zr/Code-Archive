/*************************************************************************
	> File Name: 1.LeetCode1544.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月02日 星期一 08时06分10秒
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

string makeGood(string s) {
    while (1) {
        int flag = 0;
        for (int i = 0; i < (int) s.size() - 1; i++) {
            if (abs(s[i] - s[i + 1]) == 32) {
                s.erase(i, 2);
                flag = 1;
                break;
            }
        }
        if (!flag) break;
    }
    return s;
}

int main() {
    string s;
    cin >> s;
    cout << makeGood(s) << endl;
    return 0;
}
