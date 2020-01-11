/*************************************************************************
	> File Name: 1.HOJ380.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月04日 星期六 07时42分33秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
#define max_n 1000
using namespace std;

typedef struct animal {
    int number;
    string t;
} Animal;

Animal a[max_n + 5];

int cmp(Animal x, Animal y) {
    return x.t <= y.t;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i].number = i;
        cin >> a[i].t;
    }
    sort(a + 1, a + n + 1, cmp);
    cout << a[1].number << endl << a[1].t << endl;
    return 0;
}
