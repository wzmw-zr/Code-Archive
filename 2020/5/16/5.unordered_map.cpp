/*************************************************************************
	> File Name: 5.unordered_map.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月16日 星期六 19时32分07秒
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<map>
#include<algorithm>
using namespace std;

int main() {
    unordered_map<double, int> h;
    h[2.3] = 123;
    h[345.6] = 123456;
    cout << h[2.3] << endl;
    cout << h[345.6] << endl;
    cout << h[8] << endl;
    return 0;
}
