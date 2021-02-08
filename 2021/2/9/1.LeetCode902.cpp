/*************************************************************************
	> File Name: 1.LeetCode902.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月09日 星期二 00时02分03秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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

int subarraysWithKDistinct(vector<int>& A, int K) {
    int n = A.size(), l = 0, r = 0, ans = 0;
    int cnt[20010], temp[20010];
    memset(cnt, 0, sizeof(cnt));
    memset(temp, 0, sizeof(temp));
    int num = 0;
    while (r < n) {
        if (!cnt[A[r]]) num++;
        cnt[A[r]]++;
        if (num == K) ans++;
        else if (num > K) {
            while (num > K) {
                memset(temp, 0, sizeof(temp));
                if (!(--cnt[A[l++]])) {
                    num--;
                    ans++;
                    break;
                }
                int cnt_t = 0;
                for (int i = l; i < r; i++) {
                    if (!temp[A[i]]) cnt_t++;
                    temp[A[i]]++;
                    if (cnt_t == K) ans++;
                }
            }
        }
        r++;
    }
    if (num == K && r - l > K) {
        while (num == K) {
            memset(temp, 0, sizeof(temp));
            if (!(--cnt[A[l++]])) {
                num--;
                break;
            }
            int cnt_t = 0;
            for (int i = l; i < r; i++) {
                if (!temp[A[i]]) cnt_t++;
                temp[A[i]]++;
                if (cnt_t == K) ans++;
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
