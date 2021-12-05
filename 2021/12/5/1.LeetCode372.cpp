/*************************************************************************
	> File Name: 1.LeetCode372.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月05日 星期日 09时24分00秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct BigInt {
    vector<int> digits;

    BigInt() = default;
    BigInt(BigInt &&bint) : digits(move(bint.digits)) {}
    BigInt(vector<int> &&nums) : digits(move(nums)) {
        reverse(digits.begin(), digits.end());
    }

    void minus(int x) {
        vector<int> temp;
        do {
            temp.push_back(x % 10);
            x /= 10;
        } while (x);
        reverse(temp.begin(), temp.end());
        int len = temp.size();
        for (int i = 0; i < len; i++) {
            if (this->digits[i] >= temp[i]) {
                this->digits[i] -= temp[i];
                continue;
            }
            this->digits[i] = this->digits[i] + 10 - temp[i];
            this->digits[i + 1]--;
        }
        while (this->digits.size() > 1 && (*this->digits.rbegin()) == 0) this->digits.pop_back();
    }

    int operator%(int x) {
        int n = this->digits.size();
        int t = 0;
        for (int i = n - 1; i >= 0; i--) t = ((t * 10) + this->digits[i]) % x;
        return t;
    }
};

int superPow(int a, vector<int>& b) {
    int MOD = 1337;
    vector<int> pre(MOD, 1);
    unordered_map<int, int> mp;
    mp[1] = 0;
    int s, loop;
    for (int i = 1; i < MOD; i++) {
        pre[i] = (pre[i - 1] * (a % MOD)) % MOD;
        if (!mp.count(pre[i])) {
            mp[pre[i]] = i;
            continue;
        }
        s = mp[pre[i]];
        loop = i - mp[pre[i]];
        break;
    }
    int t = s;
    vector<int> temp;
    do {
        temp.push_back(t % 10);
        t /= 10;
    } while (t);
    reverse(temp.begin(), temp.end());
    if (b.size() < temp.size() || (b.size() == temp.size() && b < temp)) {
        t = 0;
        for (int x : b) t = t * 10 + x;
        return mp[t];
    }
    BigInt bint(move(b));
    bint.minus(s);
    t = bint % loop;
    return pre[s + t];
}

int main() {
    return 0;
}
