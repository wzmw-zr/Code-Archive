/*************************************************************************
	> File Name: 8.LeetCode1530.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月30日 星期四 22时55分08秒
 ************************************************************************/

#include<iostream>
using namespace std;

int cnt[15];

void init() {
    int p = 1;
    for (int i = 1; i < 10; i++) {
        cnt[i] = 10 * cnt[i - 1] + p;
        p *= 10;
    }
}

int GetLen(int n) {
    if (n == 0) return 1;
    int len = 0;
    while (n) {
        len++;
        n /= 10;
    }
    return len;
}

int GetTopNum(int n) {
    int num = n;
    while (n) {
        num = n;
        n /= 10;
    }
    return num;
}

int numberOf2sInRange(int n) {
    int len = GetLen(n);
    if (len == 1) {
        if (n >= 2) return 1;
        return 0;
    }
    int top_num = GetTopNum(n);
    int step = 1, ret = 0;
    for (int i = 1; i < len; i++) step *= 10;
    int rest = n - top_num * step;
    ret += top_num * cnt[len - 1];
    if (top_num > 2) {
        ret += step;
        ret += numberOf2sInRange(rest);
    } else if (top_num == 2) {
        ret += rest + 1; 
        ret += numberOf2sInRange(rest);
    } else {
        ret += numberOf2sInRange(rest);
    }
    return ret;
}

int main() {
    init();
    for (int i = 1; i <= 10; i++) cout << cnt[i] << " ";
    cout << endl;
    int n;
    cin >> n;
    cout << numberOf2sInRange(n) << endl;
    return 0;
}
