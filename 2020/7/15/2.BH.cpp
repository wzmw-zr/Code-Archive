/*************************************************************************
	> File Name: 2.BH.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月15日 星期三 15时34分23秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int odd, even;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x & 1) odd++;
        else even++;
    }
    cout << (even > odd ? "NO" : "YES") << endl;
    return 0;
}
