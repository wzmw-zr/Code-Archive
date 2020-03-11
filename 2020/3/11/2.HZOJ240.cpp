/*************************************************************************
	> File Name: 2.HZOJ240.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月11日 星期三 18时03分58秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

char ans[2200][2200];
int num[10] = {0, 1, 3, 9, 27, 81, 243, 729, 2187};

void func(int x, int y, int n) {
    if (n == 1) {
        ans[x][y] = 'X';
        return ;
    }
    func(x, y, n - 1);
    func(x, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3 * 2,  y, n - 1);
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3, y + num[n] / 3, n - 1);
}

int main() {
    func(1, 1, 7);
    int n;
    while (cin >> n) {
        if (n == -1) break;
        for (int i = 1; i <= num[n]; i++) {
            for (int j = 1; j <= num[n]; j++) {
                if (ans[i][j] == 'X') cout << 'X';
                else cout << ' ';
            }
            cout << endl;
        }
        cout << '-' << endl;
    }
}
