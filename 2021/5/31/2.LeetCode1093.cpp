/*************************************************************************
	> File Name: 2.LeetCode1093.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月31日 星期一 00时08分32秒
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


vector<double> sampleStats(vector<int>& count) {
    double mmin, mmax, avg, mid, most;
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i <= 255; i++) {
        if (!count[i]) continue;
        mmin = i;
        break;
    }
    for (int i = 255; i >= 0; i--) {
        if (!count[i]) continue;
        mmax = i;
        break;
    }
    for (long i = 0; i <= 255; i++) 
        sum += i * (long) count[i], cnt += count[i];
    avg = sum / cnt;
    if (cnt & 1) {
        cnt = (cnt + 1) / 2;
        for (int i = 0; i <= 255; i++) {
            cnt -= count[i];
            if (cnt > 0) continue;
            mid = i;
            break;
        }
    } else {
        cnt /= 2;
        for (int i = 0; i <= 255; i++) {
            cnt -= count[i];
            if (cnt > 0) continue;
            if (cnt < 0) {
                mid = i;
                break;
            } else {
                for (int j = i + 1; j <= 255; j++) {
                    if (!count[j]) continue;
                    mid = i + j;
                    mid /= 2;
                    break;
                }
                break;
            }
        }
    }
    cnt = 0;
    for (int i = 0; i <= 255; i++) {
        if (count[i] <= cnt) continue;
        cnt = count[i];
        most = i;
    }
    return {mmin, mmax, avg, mid, most};
}


int main() {
    return 0;
}
