/*************************************************************************
	> File Name: 1.LeetCode7.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月03日 星期一 00时07分13秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct BigInt {
    vector<int> digits;
    long flag;

    BigInt() = default;
    BigInt(int val) {
        long t = val;
        flag = val >= 0 ? 1 : -1;
        t *= flag;
        do {
            this->digits.push_back(t % 10);
            t /= 10;
        } while (t);
        this->reverse();
    }

    bool operator<=(const BigInt &a) const {
        if (this->flag == 1 && a.flag == -1) return false;
        if (this->flag == -1 && a.flag == 1) return true;
        if (this->digits.size() < a.digits.size()) return this->flag == 1;
        if (this->digits.size() > a.digits.size()) return this->flag == -1;
        int n = this->digits.size();
        for (int i = 0; i < n; i++) {
            if (this->digits[i] == a.digits[i]) continue;
            if (this->digits[i] < a.digits[i]) return this->flag == 1;
            return this->flag == -1;
        }
        return true;
    }

    bool operator>=(const BigInt &a) const {
        if (this->flag == 1 && a.flag == -1) return true;
        if (this->flag == -1 && a.flag == 1) return false;
        if (this->digits.size() > a.digits.size()) return this->flag == 1;
        if (this->digits.size() < a.digits.size()) return this->flag == -1;
        int n = this->digits.size();
        for (int i = 0; i < n; i++) {
            if (this->digits[i] == a.digits[i]) continue;
            if (this->digits[i] > a.digits[i]) return this->flag == 1;
            return this->flag == -1;
        }
        return true;
    }

    void reverse() {
        int n = this->digits.size();
        int l = 0, r = n - 1;
        while (l < r) swap(this->digits[l++], this->digits[r--]);
    }

    int to_int() {
        int ans = 0;
        int n = this->digits.size();
        for (int i = 0; i < n; i++) 
            ans = ans * 10 + this->digits[i];
        ans *= this->flag;
        return ans;
    }
};

int reverse(int x) {
    BigInt mmax = BigInt(INT32_MAX);
    BigInt mmin = BigInt(INT32_MIN);
    BigInt num = BigInt(x);
    num.reverse();
    if (num >= mmin && num <= mmax) return num.to_int();
    return 0;
}

int main() {
    int x;
    cin >> x;
    cout << reverse(x) << endl;
    return 0;
}
