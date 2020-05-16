/*************************************************************************
	> File Name: 2.CSP.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月16日 星期六 15时29分35秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int a, b, c, flag;
int num[10], check[10];
int number[1000];


void func(int ind) {
    if (ind == 10) {
        int x[3];
        x[0] = num[1] * 100 + num[2] * 10 + num[3];
        x[1] = num[4] * 100 + num[5] * 10 + num[6];
        x[2] = num[7] * 100 + num[8] * 10 + num[9];
        sort(x, x + 3);
        if (x[0] * b == x[1] * a && x[1] * c == x[2] * b && x[0] * c == x[2] * a) {
            if (number[x[0]]) return ;
            flag = 1;
            cout << x[0] << " " << x[1] << " " << x[2] << endl;
            number[x[0]] = number[x[1]] = number[x[2]] = 1;
        }
    }
    for (int i = 1; i <= 9; i++) {
        if (check[i]) continue;
        num[ind] = i;
        check[i] = 1;
        func(ind + 1);
        check[i] = 0;
    }
}

int main() {
    cin >> a >> b >> c;
    func(1);
    !flag && cout << "No!!" << endl;
    return 0;
}
