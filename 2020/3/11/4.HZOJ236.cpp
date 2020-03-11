/*************************************************************************
	> File Name: 4.HZOJ236.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月11日 星期三 19时25分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n, m;
int number[15];

void print(int *number, int cnt, int num) {
    if (cnt == m)  {
        for (int i = 0; i < m; i++) {
            i && cout << " ";
            cout << number[i];
        }
        cout << endl;
        return ;
    }
    for (int i = num; i <= n; i++) {
        number[cnt] = i;
        print(number, cnt + 1, i + 1);
    }
}

int main() {
    cin >> n >> m;
    print(number, 0, 1);
    return 0;
}
