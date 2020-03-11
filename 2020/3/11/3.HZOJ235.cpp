/*************************************************************************
	> File Name: 3.HZOJ235.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月11日 星期三 18时58分58秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

int num[15], cnt, n;

void p() {
    for (int i = 0; i < cnt; i++) {
        if (i) cout << " ";
        cout << num[i];
    }
    cout << endl;
}

void func(int s) {
    for (int i = s; i <= n; i++) {
        num[cnt++] = i;
        p();
        func(i + 1);
        cnt--;
    } 
}


int main() {
    cin >> n;
    func(1);
    return 0;
}
