/*************************************************************************
	> File Name: 3.set.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月16日 星期六 18时12分50秒
 ************************************************************************/

#include<iostream>
#include<set>
using namespace std;

set<int> s;

int main() {
    s.insert(2);
    s.insert(1);
    s.insert(3);
    cout << *(s.begin()) << endl;
    s.erase(s.begin());
    cout << *(s.begin()) << endl;
    return 0;
}
