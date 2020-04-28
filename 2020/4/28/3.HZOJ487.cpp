/*************************************************************************
	> File Name: 3.HZOJ487.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月28日 星期二 11时59分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n;
int val[4];

int main() {
    cin >> n;
    val[1] = 2;
    val[2] = 2;
    for (int i = 3; i <= n; i++) {
        val[3] = val[1] + val[2];
        val[1] = val[2];
        val[2] = val[3];
    }
    if (n < 3) cout << val[n] << endl;
    else cout << val[3] << endl;
    return 0;
}
