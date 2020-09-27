/*************************************************************************
	> File Name: 4.1002.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月27日 星期日 11时22分29秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define SIS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

unsigned long long k1, k2;
unsigned long long xorShift128Plus() {
unsigned long long k3 = k1, k4 = k2;
k1 = k4;
k3 ^= k3 << 23;
k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
return k2 + k4;
}

int n;
long long a[1000001];

int t, q;

void gen() {
scanf("%d %llu %llu", &n, &k1, &k2);
for (int i = 1; i <= n; i++) {
a[i] = xorShift128Plus() % 999999999999 + 1;
}
}

set<unsigned long long> unpaid, paid;

char op;
unsigned long long x;

void init() {
    paid.clear();
    unpaid.clear();
    for (int i = 1; i <= n; i++) unpaid.insert(a[i]);
}

int main() {
    //SIS;
    cin >> t;
    while (t--) {
        gen();
        init();
        cin >> q;
        while (q--) {
            cin >> op >> x;
            //cout << op << " " << x << endl;
            switch (op) {
                case 'F' : {
                    int flag = 0;
                    for (auto it = unpaid.begin(); it != unpaid.end(); it++) {
                        if (*it < x) continue;
                        flag = 1;
                        cout << *it << endl;
                        break;
                    }
                    !flag && cout << "1000000000000" << endl;
                } break;
                case 'D' : {
                    for (auto it = unpaid.begin(); it != unpaid.end(); it++) {
                        if (*it < x) continue;
                        //cout << *it << endl;
                        paid.insert(*it);
                        unpaid.erase(it);
                        break;
                    }
                } break;
                case 'C' : {
                    long long ans = 0;
                    for (auto &num : unpaid) {
                        if (num <= x) ans += num;
                        else break;
                    }
                    cout << ans << endl;
                } break;
                case 'R' : {
                    //cout << "handle R" << endl;
                    while (!paid.empty()) {
                        auto it = paid.begin();
                        if (*it <= x) {
                            unpaid.insert(*it);
                            paid.erase(it);
                        } else break;
                    }
                } break;
            }
        }
    }
    return 0;
}
