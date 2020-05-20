/*************************************************************************
	> File Name: 2.HZOJ514.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月20日 星期三 18时13分23秒
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int n, ans;
int mmap[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int check[10];

int func(int x) {
    if (x == 0) return mmap[0];
    int sum = 0;
    while (x) {
        sum += mmap[x % 10];
        x /= 10;
    }
    return sum;
}

void func() {
    for (int i = 0; i <= 1111; i++) {
        for (int j = 0; j <= 1111; j++) {
            if (func(i) + func(j) + func(i + j) + 4 == n) ans++;
        }
    }
}

int main() {
    cin >> n;
    func();
    cout << ans << endl;
    return 0;
}
