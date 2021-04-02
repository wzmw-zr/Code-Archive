/*************************************************************************
	> File Name: 3.LeetCode1291.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月02日 星期五 21时24分06秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int get_len(int n) {
    int len = 0;
    while (n) {
        n /= 10;
        len++;
    }
    return len;
}

int calculate(int start, int len) {
    int ans = 0;
    for (int i = 0; i < len; i++) ans = ans * 10 + start + i;
    return ans;
}

vector<int> sequentialDigits(int low, int high) {
    int len1 = get_len(low);
    int len2 = get_len(high);
    vector<int> ans;
    for (int i = len1; i <= len2; i++) {
        for (int j = 1; j <= (9 - i + 1); j++) {
            int num = calculate(j, i);
            if (num >= low && num <= high) ans.push_back(num);
        }
    }
    return ans;
}

int main() {
    int low, high;
    cin >> low >> high;
    auto ans = sequentialDigits(low, high);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
