/*************************************************************************
	> File Name: 2.template_add.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月31日 星期五 09时17分13秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

template<typename T, typename U>
auto add(T *a, U *b) -> decltype(add(*a, *b)) {
    return add(*a, *b);
}

template<typename T, typename U, typename V>
auto add(T a, U b, V c) -> decltype(a + b + c) {
    return a + b + c;
}

int main() {
    cout << add(2, 3) << endl;
    cout << add(2.3, 4.5) << endl;
    double a = 3.0;
    int b = 1;
    decltype(a + b) c;
    cout << sizeof(c) << endl;
    return 0;
}
