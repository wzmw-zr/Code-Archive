/*************************************************************************
	> File Name: 5.2017F.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月17日 星期四 22时06分15秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX_N 100010

int t, n;
int num[MAX_N];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        memset(num, 0, sizeof(num));
        num[1] = 1, num[2] = 1;
        for (int i = 3; i <= n; i++) {
            num[i] = num[i - 2] + 1;
        }
        for (int i = 1; i <= n; i++) {
            (i - 1) && cout << " ";
            cout << num[i];
        }
        cout << endl;
    }
    return 0;
}
