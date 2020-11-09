/*************************************************************************
	> File Name: 34.HOJ463.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 20时45分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
using namespace std;

typedef struct window {
    int left, right, up, down;
} Window;

int main() {
    Window w1, w2;
    cin >> w1.left >> w1.right >> w1.up >> w1.down;
    cin >> w2.left >> w2.right >> w2.up >> w2.down;
    if (w1.left >= w2.right || w1.down >= w2.up) cout << 0;
    else if (w2.left >= w1.right || w2.down >= w1.up) cout << 0;
    else if (w1.left < w2.right && w1.down < w2.up)
        cout << (w2.right - w1.left) * (w2.up - w1.down);
    else if (w2.left < w1.right && w2.down < w1.up) 
        cout << (w1.right - w2.left) * (w1.up - w2.down);
    return 0;
}
