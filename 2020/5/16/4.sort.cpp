/*************************************************************************
	> File Name: 4.sort.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月16日 星期六 19时21分58秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int a[100] = {11, 5, 8, 3, 2, 1};
    sort(a, a + 6, cmp);
    for (int i = 0; i < 6; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
