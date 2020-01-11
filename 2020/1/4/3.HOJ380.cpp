/*************************************************************************
	> File Name: 3.HOJ380.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月04日 星期六 08时55分30秒
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
    if (x.t.length() == y.t.length()) {
        for (int i = 0; i < x.t.length(); i++) {
            if (x.t[i] == y.t[i]) continue;
            return x.t[i] > y.t[i];
        }
        return 1;
    }
    return x.t.length() > y.t.length();
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t;
        a[i].number = i;
    }
    sort(a + 1, a + n + 1, cmp);
    cout << a[1].number << endl << a[1].t << endl;
    return 0;
}
