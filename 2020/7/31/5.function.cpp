/*************************************************************************
	> File Name: 5.function.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月31日 星期五 17时51分20秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

int main() {
    function<void(int, int)> add = [=](int x, int y) -> void {
        cout << x + y << "is a number" << endl;
    };
    add(4, 5);
    return 0;
}
