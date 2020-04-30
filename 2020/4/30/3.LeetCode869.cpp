/*************************************************************************
	> File Name: 3.LeetCode869.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月30日 星期四 17时34分19秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int cnt[10];
int data[10];

int GetLen(int n) {
    int len = 0;
    while (n) {
        n /= 10;
        len++;
    }
    return len;
}

void init(int n) {
    while (n) {
        int t = n % 10;
        n /= 10;
        cnt[t]++;
    }
}

bool Check(int len) {
    int num = 1;
    for (int i = 0; i <= 31; i++) {
        int l = GetLen(num); 
        if (l > len) break;
        if (l < len) {
            num <<= 1;
            continue;
        }
        int tmp = num;
        memset(data, 0, sizeof(data));
        while (tmp) {
            int t = tmp % 10;
            data[t]++;
            tmp /= 10;
        }
        int flag = 0;
        for (int i = 0; !flag && i < 10; i++) {
            if (cnt[i] == data[i]) continue;
            flag = 1;
        }
        if (!flag) return true;
        num <<= 1;
    }
    return false;
}

bool reorderedPowerOf2(int N) {
    int len = GetLen(N);
    init(N);
    return Check(len);
}

int main() {
    int n;
    cin >> n;
    cout << (reorderedPowerOf2(n) ? "Yes" : "No") << endl;
    return 0;
}
