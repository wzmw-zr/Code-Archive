/*************************************************************************
	> File Name: 3.template_type.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月31日 星期五 11时05分46秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

template<typename T>
void my_swap(T &a, T &b) {
    T c;
    c = a;
    a = b;
    b = c;
    return ;
}

int main() {
    int a = 123, b = 456;
    my_swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}
