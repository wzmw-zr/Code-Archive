/*************************************************************************
	> File Name: 3.LeetCode5773.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月30日 星期日 10时38分07秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string maxValue(string n, int x) {
    string ans = "";
    if (n[0] != '-') {
        int ind = n.size();
        for (int i = 0; n[i]; i++) {
            if (n[i] >= x + '0') continue;
            ind = i;
            break;
        }
        for (int i = 0; i < ind; i++) ans += n[i];
        ans += x + '0';
        for (int i = ind; n[i]; i++) ans += n[i];
    } else {
        ans += "-";
        int ind = n.size();
        for (int i = 1; n[i]; i++) {
            if (n[i] <= x + '0') continue;
            ind = i;
            break;
        }
        for (int i = 1; i < ind; i++) ans += n[i];
        ans += x + '0';
        for (int i = ind; n[i]; i++) ans += n[i];
    }
    return ans;
}

int main() {
    string n;
    int x;
    cin >> n >> x;
    cout << maxValue(n, x) << endl;
    return 0;
}
