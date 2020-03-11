/*************************************************************************
	> File Name: 5.HZOJ237.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月11日 星期三 19时34分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int n, number[10], exist[10];

void output(int *number, int ind, int cnt) {
    if (cnt == n + 1) {
        for (int i = 0; i < n; i++) {
            i && cout << " ";
            cout << number[i];
        }
        cout << endl;
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (exist[i]) continue;
        number[ind] = i;
        exist[i] = 1;
        output(number, ind + 1, cnt + 1);
        exist[i] = 0;
    }
}

int main() {
    cin >> n;
    output(number, 0, 1);
    return 0;
}
