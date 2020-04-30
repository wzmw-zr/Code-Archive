/*************************************************************************
	> File Name: 2.HZOJ469.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月30日 星期四 15时43分52秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

int x;
string n;

int res(int x, string n) {
    int ret = 0;
    for (int i = 0; i < n.size(); i++) {
        ret *= x;
        ret += n[i] - '0';
    }
    return ret;
}

int main() {
    cin >> x >> n;
    cout << res(x, n) << endl;
    return 0;
}
