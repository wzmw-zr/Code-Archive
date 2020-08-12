/*************************************************************************
	> File Name: 3.NewCode.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月12日 星期三 19时52分58秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
#define MAX_N 100000

int n;
int num[MAX_N + 5];
int cnt[MAX_N + 5];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    for (int i = 0; i < n; i++) cnt[i] = 1;
    stack<int> st_1, st_2;
    for (int i = 0; i < n; i++) {
        while ((!st_1.empty()) && (num[st_1.top()] <= num[i])) {
            st_1.pop();
            cnt[i]++;
        }
        cnt[i] += st_1.size();
        st_1.push(i);
    }
    for (int i = n - 1; i >= 0; i--) {
        while ((!st_2.empty()) && (num[st_2.top()] <= num[i])) {
            st_2.pop();
            cnt[i]++;
        }
        cnt[i] += st_2.size();
        st_2.push(i);
    }
    for (int i = 0; i < n; i++) cout << cnt[i] << " ";
    cout << endl;
    return 0;
}
