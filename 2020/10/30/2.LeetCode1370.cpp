/*************************************************************************
	> File Name: 2.LeetCode1370.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月30日 星期五 08时39分40秒
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

int find_next_min(string &s, char c, vector<int> &check) {
    int ind = -1;
    char c_t = 'z' + 1;
    for (int i = 0; s[i]; i++) {
        if (check[i]) continue;
        if (s[i] <= c) continue;
        if (c_t <= s[i]) continue;
        c_t = s[i];
        ind = i;
    }
    return ind;
}

int find_next_max(string &s, char c, vector<int> &check) {
    int ind = -1;
    char c_t = 'a' - 1;
    for (int i = 0; s[i]; i++) {
        if (check[i]) continue;
        if (s[i] >= c) continue;
        if (c_t >= s[i]) continue;
        c_t = s[i];
        ind = i;
    }
    return ind;
}

string sortString(string s) {
    int len = s.size(), flag = 0;
    vector<int> check(len + 5, 0);
    char c = 'a' - 1;
    for (int i = 1; i <= len; ) {
        if (!flag) {
            int ind = find_next_min(s, c, check);
            if (ind == -1) {
                c = 'z' + 1;
                flag = 1;
                continue;
            } else {
                check[ind] = i++;
                c = s[ind];
            }
        } else {
            int ind = find_next_max(s, c, check);
            if (ind == -1) {
                c = 'a' - 1;
                flag = 0;
                continue;
            } else {
                check[ind] = i++;
                c = s[ind];
            }
        }
    }
    for (int i = 0; i < len; i++) cout << check[i] << " ";
    cout << endl;
    string ans(len, '\0');
    for (int i = 0; i < len; i++) ans[check[i] - 1] = s[i];
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << sortString(s) << endl;
    return 0;
}
