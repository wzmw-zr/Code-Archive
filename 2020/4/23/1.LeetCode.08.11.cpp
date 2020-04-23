/*************************************************************************
	> File Name: 1.LeetCode.08.11.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月23日 星期四 07时27分12秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

int waysToChange(int n) {
    int coin[4] = {1, 5, 10, 25}, num[n + 5] = {0};
    for (int j = 0; j <= n; j++) num[j] = 1;
    for (int i = 1; i < 4; i++) {
        cout << i << endl;
        for (int j = 1; j <= n; j++) {
            cout << "num[" <<  j << "] = " << num[j] << endl;
            if (j >= coin[i]) num[j] = (num[j] + num[j - coin[i]]) % 1000000007;
            cout << "num[" <<  j << "] = " << num[j] << endl;
        }
        cout << endl;
    }
    return num[n];
}

int main() {
    int n;
    cin >> n;
    cout << waysToChange(n) << endl;
    return 0;
}
