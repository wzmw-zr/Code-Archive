/*************************************************************************
	> File Name: 8.sort.name.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月24日 星期二 20时31分26秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
using namespace std;

struct Stu {
    char name[25];
} arr[10];


int cmp(struct Stu a, struct Stu b) {
    int t = strcmp(a.name, b.name);
    return t < 0;
}

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> arr[i].name;
    }
    sort(arr, arr + 10, cmp);
    for (int i = 0; i < 10; i++) {
        cout << arr[i].name << endl;
    }
    return 0;
}
