/*************************************************************************
	> File Name: 5.HZOJ256.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月23日 星期四 19时33分32秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define MAX_N 1000

int a[MAX_N + 5], b[MAX_N + 5], ind[MAX_N + 5];

bool cmp(int i, int j) {
    return a[i] * b[i] < a[j] * b[j];
}


struct BigInt : vector<int> {
    BigInt() {}

    BigInt(int x) {
        push_back(x);
        process_digit();
    }

    BigInt(vector<int> &v) : vector<int>(v) { process_digit(); }

    void process_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size() - 1) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while (size() > 1 && at(size() - 1) == 0) pop_back();
        return ;
    }

    BigInt operator/(int x) {
        int y = 0;
        vector<int> ret(size());
        for (int i = size() - 1; i >= 0; i--)  {
            y = y * 10 + at(i);
            ret[i] = y / x;
            y %= x;
        }
        while (ret.size() > 1 && ret[ret.size() - 1] == 0) ret.pop_back();
        return ret;
    }

    void operator*=(int x)  {
        for (int i = 0; i < size(); i++) at(i) *= x;
        process_digit();
    }

    bool operator>(const BigInt &a) {
        if (size() - a.size()) return size() > a.size();
        for (int i = size() - 1; i >= 0; i++) {
            if (at(i) - a[i]) return at(i) > a[i];
        }
        return false;
    }
};


ostream &operator<<(ostream &out, const BigInt &v) {
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a[i] >> b[i];
        ind[i] = i;
    }
    sort(ind + 1, ind + n + 1, cmp);
    BigInt p = a[ind[0]], ans = 0;
    for (int i = 1; i <= n; i++) {
        BigInt tmp = p / b[ind[i]];
        if (tmp > ans) ans = tmp;
        p *= a[ind[i]];
    }
    cout << ans << endl;
    return 0;
}
