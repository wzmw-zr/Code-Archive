/*************************************************************************
	> File Name: 6.LeetCode556.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月04日 星期二 22时35分30秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct BigInt {
    vector<int> digits;

    BigInt() = default;
    BigInt(int val) {
        do {
            this->digits.push_back(val % 10);
            val /= 10;
        } while (val);
        this->reverse_digits();
    }

    void reverse_digits() {
        int l = 0, r = (int) this->digits.size() - 1;
        while (l < r) {
            swap(this->digits[l], this->digits[r]);
            l++, r--;
        }
    }
    
    void get_next() {
        int n = this->digits.size();
        int i = n - 1;
        for (i = n - 1; i >= 0; i--) {
            if (i == n - 1) continue;
            if (this->digits[i] >= this->digits[i + 1]) continue;
            int r = i + 1;
            while ((r < n) && (this->digits[i] < this->digits[r])) r++;
            r--;
            swap(this->digits[i], this->digits[r]);
            break;
        }
        sort(this->digits.begin() + i + 1, this->digits.end());
    }

    bool operator<(const struct BigInt &a) const {
        int len_1 = this->digits.size(), len_2 = a.digits.size();
        if (len_1 != len_2) return len_1 < len_2;
        for (int i = 0; i < len_1; i++) {
            if (this->digits[i] == a.digits[i]) continue;
            return this->digits[i] < a.digits[i];
        }
        return false;
    }

    int to_int() {
        int ans = 0;
        for (int x : this->digits) 
            ans = ans * 10 + x;
        return ans;
    }
};


int nextGreaterElement(int n) {
    BigInt num(n);
    BigInt mmax(INT32_MAX);
    num.get_next();
    if (mmax < num) return -1;
    int t = num.to_int();
    if (t <= n) return -1;
    return t;
}

int main() {
    int n;
    cin >> n;
    cout << nextGreaterElement(n) << endl;
    return 0;
}
